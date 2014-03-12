#ifndef LC_CORE_H
#define LC_CORE_H

#include "public/util.h"
#include <vector>

struct Interface;
typedef void (*LogSink)(const char* name, const char* log);

class Core : 
    public ITimer, 
    public IInterfaceSet,
    public IEvent {
 public:
  Core(LogSink log_sink);
  virtual ~Core(void);

  int Run(std::vector<const char*>& argv);
 public:
  virtual void* Add(timeval* tv, TimerFunc cb, void *ctx, bool persist = false);

  virtual void  Del(void* handle);

  virtual Interface* Get(const std::string& if_name);

  virtual int Add(const std::string& if_name, Interface *interface);

  virtual event_base* EventBase(void);
 private:
  struct Impl;
  Impl *pimpl_;
};

#endif // LC_CORE_H

