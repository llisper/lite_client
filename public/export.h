#ifndef LC_EXPORT_H
#define LC_EXPORT_H

#include <vector>

#define EXPORT_DROID(name) \
  extern "C" Droid* onload(std::vector<const char*>& argv) { \
    return new name(argv); \
  } \
  extern "C" void unload(Droid* d) { delete d; }

#define EXPORT_DROID_NOARG(name) \
  extern "C" Droid* onload(std::vector<const char*>& argv) { \
    return new name; \
  } \
  extern "C" void unload(Droid* d) { delete d; }

#define ADD_INTERFACE(if_name) ({ \
  const char *n = if_name; \
  int retcode = util()->if_set->Add(n, this); \
  if (0 != retcode) return retcode; \
  retcode; })

#endif // LC_EXPORT_H

