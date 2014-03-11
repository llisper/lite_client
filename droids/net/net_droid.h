#ifndef LC_NET_DROID_H
#define LC_NET_DROID_H

#include "public/droid.h"
#include "public/interface/net.h"

#include <map>

struct DroidInit;
struct bufferevent;

class NetDroid : 
    public Droid,
    public INet {
 public:  
  NetDroid(void);
  virtual ~NetDroid(void);

  virtual int Init(DroidInit* dinit);
  virtual int Destroy(void);

  virtual int OpenSession(sockaddr* sa, int sa_len, OpenSessionCallback cb, void *ctx);
  virtual int CloseSession(int id);
  virtual int Sniff(int id, const char*& dptr, size_t& sz);
  virtual int Drain(int id, size_t sz);
  virtual int Send(int id, const char* dptr, size_t sz);

  struct Impl;
 private:
  Impl *pimpl_;
};

#endif // LC_NET_DROID_H

