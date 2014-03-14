#include "use_dlog.h"
#include "public/droid.h"
#include "public/util.h"
#include "public/export.h"
#include "public/interface/dispatcher.h"

#include <map>

class Dispatcher : public Droid, public IDispatcher {
 public:
  virtual ~Dispatcher(void) {}
  virtual int  Init(void);
  virtual int  Destroy(void);
  virtual int  Subscribe(int id, Handler handler, void *ctx);
  virtual void Unsubscribe(int key);
  virtual int  Publish(int id, void *message);
 
  typedef std::pair<Handler, void*> HType;
  typedef std::map<int, HType> HandlerMap;
  HandlerMap hmap_;
};

int Dispatcher::Init(void) {
  DLOG_INIT(util());
  ADD_INTERFACE("IDispatcher");
  return 0; 
}

int Dispatcher::Destroy(void) { 
  util()->if_set->Del("IDispatcher");
  return 0; 
}

int Dispatcher::Subscribe(int id, Handler handler, void *ctx) {
  HandlerMap::iterator it = hmap_.find(id);
  if (it != hmap_.end()) {
    DLOG("id {%d} is already exists", id);
    return -1;
  }

  hmap_.insert(it, HandlerMap::value_type(id, std::make_pair(handler, ctx)));
  DLOG("id {%d} subscribed", id);
  return 0;
}

void Dispatcher::Unsubscribe(int id) {
  hmap_.erase(id);
  DLOG("id {%d} unsubscribed", id);
}

int Dispatcher::Publish(int id, void *message) {
  HandlerMap::iterator it = hmap_.find(id);
  if (it == hmap_.end()) {
    DLOG("id {%d} doesn't have a handler subscribed, ignore", id);
    return -1;
  }

  DLOG("publish for id {%d}", id);

  Handler h = (*it).second.first;
  void *ctx = (*it).second.second;
  return h(message, ctx);
}

EXPORT_DROID_NOARG(Dispatcher);

