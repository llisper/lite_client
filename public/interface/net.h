#ifndef LC_NET_H
#define LC_NET_H

#include "public/interface/interface.h"
#include <sys/types.h>

struct sockaddr_in;
typedef void (*OpenSessionCallback)(ssize_t, void*);
class INet : public Interface {
 public:
  virtual int OpenSession(sockaddr_in *sin, OpenSessionCallback cb, void *ctx) = 0;
  virtual int CloseSession(size_t id) = 0;
  virtual int Sniff(size_t id, const char*& dptr, size_t& sz) = 0;
  virtual int Drain(size_t id, size_t sz) = 0;
  virtual int Send(size_t id, const char *dptr, size_t sz) = 0;
};

#endif // LC_NET_H

