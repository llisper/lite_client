#ifndef LC_PROTOTOL_H
#define LC_PROTOTOL_H

#include "public/interface/interface.h"

class IProtocol : public Interface {
 public:
  /**
   * @brief
   *  encode a message object into binary stream
   * @param header
   *  header object, usually contains length and id stuff
   * @param msg
   *  message body
   * 
  virtual ssize_t Encode(void* header, void *msg, char *dptr, size_t& dptr_size) = 0;
  virtual ssize_t Decode(const char *dptr, size_t dptr_size, void **header, void **msg) = 0;
};

#endif // LC_PROTOTOL_H

