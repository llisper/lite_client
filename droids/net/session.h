#ifndef LC_NET_SESSION_H
#define LC_NET_SESSION_H

#include "public/cbuf.h"

class NetDroid;
struct bufferevent;
class Session {
 public:
  Session(short sid, NetDroid *nd, bufferevent *bev);
  ~Session(void);

  int Sniff(const char*& dptr, size_t& sz);

  int Drain(size_t sz);

  int Send(const char* dptr, size_t sz);
 private:
  short sid_;
  CBuf cbuf_;
  NetDroid *nd_;
  bufferevent *bev_;
};

#endif // LC_NET_SESSION_H

