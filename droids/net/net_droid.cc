#include "session.h"
#include "use_dlog.h"
#include "net_droid.h"
#include "public/id_map.h"
#include "public/util.h"
#include "public/export.h"

#include <event2/util.h>
#include <event2/event.h>
#include <event2/bufferevent.h>

#include <map>
#include <errno.h>
#include <netinet/in.h>

EXPORT_DROID_NOARG(NetDroid);

typedef std::map<size_t, Session*> SessionMap;
struct NetDroid::Impl {
  NetDroid* ref_;
  SessionMap session_map_;
  event_base *evbase_;
  IDMap<SHRT_MAX> sid_map_;
  DLog dlog_;
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
  pimpl_->ref_ = this;
}

NetDroid::~NetDroid(void) {
  delete pimpl_;
}

#define session_map (pimpl_->session_map_)
#define evbase (pimpl_->evbase_)
#define sid_map (pimpl_->sid_map_)

int NetDroid::Init(void) {
  evbase = util()->event->EventBase();
  DLOG_INIT(util());
  ADD_INTERFACE("INet");
  return 0;
}

int NetDroid::Destroy(void) {
  std::for_each(session_map.begin(), session_map.end(), close_session);
  session_map.clear();
  util()->if_set->Del("INet");
  return 0;
}

int NetDroid::OpenSession(sockaddr_in *sin, OpenSessionCallback cb, void *ctx) {
  size_t sid;
  if (!sid_map.Next(sid)) {
    DLOG("alloc sid failed");
    return -1;
  }

  bufferevent *bev = bufferevent_socket_new(evbase, -1, BEV_OPT_CLOSE_ON_FREE);
  if (!bev) {
    DLOG("bufferevent_socket_new failed");
    sid_map.Free(sid);
    return -2;
  }

  PendingConn *pending_conn = new PendingConn;
  pending_conn->net_impl = pimpl_;
  pending_conn->sid = sid;
  pending_conn->cb = cb;
  pending_conn->ctx = ctx;
  bufferevent_setcb(bev, NULL, NULL, bev_event, pending_conn);

  if (0 != bufferevent_socket_connect(bev, (sockaddr*)sin, sizeof(*sin))) {
    DLOG("bufferevent_socket_connect failed");
    delete pending_conn;
    sid_map.Free(sid);
    return -3;
  }

  char addr[INET_ADDRSTRLEN];
  DLOG("try to establish session {%d} to {%s:%d}", sid,
       evutil_inet_ntop(sin->sin_family, &(sin->sin_addr), addr, INET_ADDRSTRLEN), 
       sin->sin_port);
  return 0;
}

#define FIND_SESSION(id) ({ \
    SessionMap::iterator it = session_map.find(id); \
    if (it == session_map.end()) \
    return -1; \
    (*it).second;})

int NetDroid::CloseSession(size_t id) {
  SessionMap::iterator it = session_map.find(id);
  if (it == session_map.end()) 
    return -1; 

  Session *s = (*it).second;
  DLOG("close session {%d}", s->sid());
  sid_map.Free(s->sid());
  delete s;
  session_map.erase(it);
  return 0;
}

int NetDroid::Sniff(size_t id, const char*& dptr, size_t& sz) {
  Session *s = FIND_SESSION(id);
  return s->Sniff(dptr, sz);
}

int NetDroid::Drain(size_t id, size_t sz) {
  Session *s = FIND_SESSION(id);
  return s->Drain(sz);
}

int NetDroid::Send(size_t id, const char* dptr, size_t sz) {
  Session *s = FIND_SESSION(id);
  return s->Send(dptr, sz);
}

#undef FIND_SESSION
#undef session_map
#undef evbase
#undef sid_map

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
    Session *s = new Session(sid, net_impl->ref_, bev);
    net_impl->session_map_[sid] = s;

    cb(sid, cbarg);
    DLOG("session {%d} established", sid);
    return;
  } else if (what & BEV_EVENT_ERROR) {
    int errcode = evutil_socket_geterror();
    const char* error = evutil_socket_error_to_string(errcode);
    DLOG("session {%d} failed to establish, what {%s}", sid, error); 
  } else {
    DLOG("session {%d} failed to establish, what {%d}", sid, what);
  }

  cb(-1, cbarg); 
  net_impl->sid_map_.Free(sid);
  bufferevent_free(bev);
  delete pending_conn;
}

