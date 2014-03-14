#include "public/util.h"
#include "public/droid.h"
#include "public/export.h"
#include "public/interface/blackboard.h"

#include <map>

class Blackboard : public Droid, public IBlackboard {
 public:
  virtual ~Blackboard(void) {}
  virtual int Init(void);
  virtual int Destroy(void);
  virtual int Set(const std::string& path, const std::string& val);
  virtual int Get(const std::string& path, std::string& val, const char *default_val = NULL) const;

  typedef std::map<std::string, std::string> ValMap;
  ValMap valmap_;
};

int Blackboard::Init(void) {
  ADD_INTERFACE("IBlackboard"); 
  return 0; 
}

int Blackboard::Destroy(void) { 
  util()->if_set->Del("IBlackboard");
  return 0; 
}

int Blackboard::Set(const std::string& path, const std::string& val) {
  ValMap::iterator it = valmap_.find(path);
  if (it == valmap_.end())
    valmap_.insert(it, ValMap::value_type(path, val));
  else
    (*it).second.assign(val);
  return 0;
}

int Blackboard::Get(const std::string& path, std::string& val, const char *default_val) const {
  ValMap::const_iterator it = valmap_.find(path);
  if (it == valmap_.end()) {
    if (!default_val)
      return -1;
    val.assign(default_val);
  } else {
    val.assign((*it).second);
  }

  return 0;
}

EXPORT_DROID_NOARG(Blackboard);

