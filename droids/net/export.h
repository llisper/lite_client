#ifndef LC_NET_EXPORT_H
#define LC_NET_EXPORT_H

#include <vector>

class Droid;
extern "C" {
  Droid* onload(std::vector<const char*>& argv);
  void unload(Droid* d);
}

#endif // LC_NET_EXPORT_H

