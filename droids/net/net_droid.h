#ifndef LC_NET_DROID_H
#define LC_NET_DROID_H

#include "public/droid.h"
#include "public/interface/net.h"

#include <map>

struct bufferevent;

class NetDroid : 
    public Droid,
    public INet {
 public:  
  NetDroid(void);
  virtual ~NetDroid(void);

  virtual int Init(void);
  virtual int Destroy(void);

  virtual int OpenSession(sockaddr_in *sin, OpenSessionCallback cb, void *ctx);
  virtual int CloseSession(size_t id);
  virtual int Sniff(size_t id, const char*& dptr, size_t& sz);
  virtual int Drain(size_t id, size_t sz);
  virtual int Send(size_t id, const char *dptr, size_t sz);

  struct Impl;
 private:
  Impl *pimpl_;
};

#endif // LC_NET_DROID_H

