#include "core/droid_holder.h"
#include "core/debug_log.h"
#include "public/util.h"
#include "public/droid.h"

#include <dlfcn.h>

typedef Droid* (*onload)(std::vector<const char*>& argv);
typedef void (*unload)(Droid*);

DroidHolder::DroidHolder(const std::string& module_path) 
  : module_path_(module_path) {
    droid_ = NULL;
    mptr_ = NULL;
  }

int DroidHolder::Load(std::vector<const char*>& argv, DroidInit *dinit) {
  mptr_ = dlopen(module_path_.c_str(), RTLD_NOW);
  if (NULL == mptr_) {
    DLOG("load {%s} failed: {%s}", module_path_.c_str(), dlerror());
    return -1;
  }

  onload f_onload = (onload)dlsym(mptr_, "onload");
  unload f_unload = (unload)dlsym(mptr_, "unload");

  if (!f_onload || !f_unload)
    return -2;

  droid_ = f_onload(argv);
  return droid_ ? droid_->Init(dinit) : -3;
}

DroidHolder::~DroidHolder(void) {
  droid_->Destroy();
  unload f_unload = (unload)dlsym(mptr_, "unload");
  f_unload(droid_);
  dlclose(mptr_);
}

