#ifndef LC_NET_H
#define LC_NET_H

#include "public/interface/interface.h"
#include <sys/socket.h>

typedef void (*OpenSessionCallback)(ssize_t, void*);
class INet : public Interface {
 public:
  virtual int OpenSession(sockaddr* sa, int sa_len, OpenSessionCallback cb, void *ctx) = 0;
  virtual int CloseSession(int id) = 0;
  virtual int Sniff(int id, const char*& dptr, size_t& sz) = 0;
  virtual int Drain(int id, size_t sz) = 0;
  virtual int Send(int id, const char* dptr, size_t sz) = 0;
};

#endif // LC_NET_H

