#include "use_dlog.h"
#include "public/droid.h"
#include "public/util.h"
#include "public/export.h"
#include "public/interface/net.h"
#include "public/interface/xjcard.h"
#include "public/interface/dispatcher.h"

#include "ProtoPack.h"
#include "CProto_Command.h"
#include "ProtoPack_Package.h"

#include <sys/time.h>

using namespace CProto;

namespace xjcard {

class Codec : public Droid, public ICodec {
 public:
  enum {
    BUFSZ = 65535,
  };

  Codec(void);
  virtual ~Codec(void) {}
  virtual int Init(void);
  virtual int Destroy(void);
  virtual int Start(size_t sid);
  virtual int Send(CProto::PackBody *packet_body);

  static void OnTick(void *ctx);

  ssize_t     sid_;
  void        *h_timer_;
  INet        *net_;
  IDispatcher *dispatcher_;
  stCSHead    header_;
  char        buffer_[BUFSZ];
};

Codec::Codec(void) : 
    sid_(-1),
    h_timer_(NULL),
    net_(NULL),
    dispatcher_(NULL)
{
  header_.uin = -1;
  header_.command = XJCMD_MAXSIZE;
  header_.sequence = 0;
  header_.timestamp = 0;
  header_.guid = -1;
}

int Codec::Init(void) { 
  DLOG_INIT(util());

  ADD_INTERFACE("xjcard.ICodec");
  net_ = (INet*)util()->if_set->Get("INet");
  dispatcher_ = (IDispatcher*)util()->if_set->Get("IDispatcher");

  timeval tv = { 0, 16000 }; // approximately 60 f/s
  h_timer_ = util()->timer->Add(&tv, Codec::OnTick, this, true);
  return (net_ && dispatcher_ && h_timer_) ? 0 : -1;
}

int Codec::Destroy(void) { 
  util()->if_set->Del("xjcard.ICodec");
  util()->timer->Del(h_timer_);
  return 0; 
}

int Codec::Start(size_t sid) {
  sid_ = sid;
  header_.uin = (unsigned int)sid;
  return 0;
}

int Codec::Send(CProto::PackBody *packet_body) {
  unsigned char *ptr = (unsigned char*)(buffer_ + 4); // skip length, set at last
  unsigned int left = BUFSZ - 4;
  unsigned int size = 0;
  size_t length = 0;

  // update header
  header_.command = (unsigned short)packet_body->CommandID();
  header_.sequence += 1;
  header_.timestamp = (unsigned int)time(NULL);

  try {
    // encode header
    size = left;
    header_.Encode(ptr, size);
    ptr += size;
    left -= size;

    // encode body
    size = left;
    packet_body->Encode(ptr, size);
    ptr += size;
    left -= size;

    // prepend length
    length = ptr - (unsigned char*)buffer_;
    h2n_32((unsigned char*)buffer_, (unsigned int)length);
  } catch (EncodeError&) {
    DLOG("encode error, packet {%d}", packet_body->CommandID());
  }

  int retcode = net_->Send(sid_, buffer_, length);
  if (0 == retcode)
    DLOG("send packet {%d}", packet_body->CommandID());
  else
    DLOG("send error {%d}, packet {%d}", retcode, packet_body->CommandID());

  return 0;
}

void Codec::OnTick(void *ctx) {
  Codec *codec = (Codec*)ctx;
  if (codec->sid_ == -1)
    return;

  int retcode;
  const char *dptr;
  size_t sz;

  static packs packet;

  retcode = codec->net_->Sniff((size_t)codec->sid_, dptr, sz);
  if (0 != retcode) {
    DLOG("sniff error {%d}", retcode);
    return;
  }

  try {
    unsigned int size = (unsigned int)sz;
    packet.Decode((const unsigned char*)dptr, size);
  } catch (DecodeError&) {
    return;
  }

  if (sz < packet.length)
    return;

  packet.Init(packet.head.command, codec->buffer_);
  try {
    unsigned int size = (unsigned int)sz;
    packet.Decode((const unsigned char*)dptr, size);
    retcode = codec->dispatcher_->Publish(packet.head.command, packet.packbody);
    DLOG("message {%d} processed, retcode {%d}", packet.head.command, retcode);
  } catch (DecodeError&) {
    DLOG("decode error, packet {%d} discard", packet.head.command);
  } catch (...) {
    DLOG("other error, probably thrown by message handler");
  }
  
  retcode = codec->net_->Drain((size_t)codec->sid_, packet.length);
  if (0 != retcode) 
    DLOG("drain error {%d}", retcode);
}

}

EXPORT_DROID_NOARG(xjcard::Codec);

