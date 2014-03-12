#ifndef LC_NET_SESSION_H
#define LC_NET_SESSION_H

#include "public/cbuf.h"

class NetDroid;
struct bufferevent;
class Session {
 public:
  Session(size_t sid, NetDroid *nd, bufferevent *bev);
  ~Session(void);

  size_t sid(void) const { return sid_; }

  int Sniff(const char*& dptr, size_t& sz);

  int Drain(size_t sz);

  int Send(const char* dptr, size_t sz);
 private:
  static void bev_event(bufferevent *bev, short what, void *ctx);
  static void bev_read(bufferevent *bev, void *ctx);

  size_t sid_;
  CBuf cbuf_;
  NetDroid *nd_;
  bufferevent *bev_;
};

#endif // LC_NET_SESSION_H

