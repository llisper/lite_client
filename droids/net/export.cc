#include "export.h"
#include "net_droid.h"

extern "C" {
  Droid* onload(std::vector<const char*>& argv) {
    return new NetDroid;
  }

  void unload(Droid* d) {
    delete d;
  }
}
