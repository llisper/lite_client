#ifndef LC_IBLACKBOARD_H
#define LC_IBLACKBOARD_H

#include "public/interface/interface.h"
#include <string>

class IBlackboard : public Interface {
 public:
  // set, get
  virtual int Set(const std::string& path, const std::string& val) = 0;
  virtual int Get(const std::string& path, std::string& val, const char *default_val = NULL) const = 0;
};

#endif // LC_IBLACKBOARD_H

