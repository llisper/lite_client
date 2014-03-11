#include "session.h"
#include "net_droid.h"
#include "public/id_map.h"
#include "public/util.h"

#include <event2/bufferevent.h>

#include <map>

typedef std::map<size_t, Session*> SessionMap;
struct NetDroid::Impl {
  NetDroid* ref__;
  SessionMap session_map__;
  event_base *evbase__;
  IDMap<SHRT_MAX> sid_map__;
};

struct PendingConn {
  NetDroid::Impl* net_impl;
  size_t sid;
  OpenSessionCallback cb;
  void *ctx;
};

static void close_session(SessionMap::value_type& v);
static void bev_event(bufferevent *bev, short what, void *ctx);

NetDroid::NetDroid(void) {
  pimpl_ = new Impl;
  pimpl_->ref__ = this;
}

NetDroid::~NetDroid(void) {
  delete pimpl_;
}

#define session_map_ (pimpl_->session_map__)
#define evbase_ (pimpl_->evbase__)
#define sid_map_ (pimpl_->sid_map__)

int NetDroid::Init(DroidInit* dinit) {
  evbase_ = dinit->event->EventBase();
}

int NetDroid::Destroy(void) {
  std::for_each(session_map_.begin(), session_map_.end(), close_session);
  session_map_.clear();
  return 0;
}

int NetDroid::OpenSession(sockaddr* sa, int sa_len, OpenSessionCallback cb, void *ctx) {
  size_t sid;
  if (!sid_map_.Next(sid))
      return -1;

  bufferevent *bev = bufferevent_socket_new(evbase_, -1, BEV_OPT_CLOSE_ON_FREE);
  if (!bev) {
    sid_map_.Free(sid);
    return -2;
  }

  PendingConn *pending_conn = new PendingConn;
  pending_conn->net_impl = pimpl_;
  pending_conn->sid = sid;
  pending_conn->cb = cb;
  pending_conn->ctx = ctx;
  bufferevent_setcb(bev, NULL, NULL, bev_event, pending_conn);

  if (0 != bufferevent_socket_connect(bev, sa, sa_len)) {
    delete pending_conn;
    sid_map_.Free(sid);
    return -3;
  }
  return 0;
}

#define FIND_SESSION(id) ({ \
    SessionMap::iterator it = session_map_.find(id); \
    if (it == session_map_.end()) \
        return -1; \
    (*it).second;})

int NetDroid::CloseSession(int id) {
    SessionMap::iterator it = session_map_.find(id);
    if (it == session_map_.end()) 
        return -1; 

    delete (*it).second;
    session_map_.erase(it);
    return 0;
}

int NetDroid::Sniff(int id, const char*& dptr, size_t& sz) {
    Session *s = FIND_SESSION(id);
    return s->Sniff(dptr, sz);
}

int NetDroid::Drain(int id, size_t sz) {
    Session *s = FIND_SESSION(id);
    return s->Drain(sz);
}

int NetDroid::Send(int id, const char* dptr, size_t sz) {
    Session *s = FIND_SESSION(id);
    return s->Send(dptr, sz);
}

#undef FIND_SESSION
#undef session_map_
#undef evbase_
#undef sid_map_

void close_session(SessionMap::value_type& v) {
  delete v.second;
}

void bev_event(bufferevent *bev, short what, void *ctx) {
  PendingConn *pending_conn = (PendingConn*)ctx;
  NetDroid::Impl* net_impl = pending_conn->net_impl;
  size_t sid = pending_conn->sid;
  OpenSessionCallback cb = pending_conn->cb;
  void *cbarg = pending_conn->ctx;

  if (what & BEV_EVENT_CONNECTED) {
    Session *s = new Session(sid, net_impl->ref__, bev);
    net_impl->session_map__[sid] = s;

    cb(sid, cbarg);
  } else {
    cb(-1, cbarg); 
    net_impl->sid_map__.Free(sid);
    bufferevent_free(bev);
  }
  delete pending_conn;
}

