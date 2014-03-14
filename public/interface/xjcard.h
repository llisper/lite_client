#ifndef LC_IXJCARD_H
#define LC_IXJCARD_H

#include "public/interface/interface.h"

namespace CProto {
class PackBody;
}

namespace xjcard {

class ICodec : public Interface {
 public:
  virtual int Start(size_t sid) = 0;
  virtual int Send(CProto::PackBody *packet_body) = 0;
};

}

#endif // LC_IXJCARD_H

