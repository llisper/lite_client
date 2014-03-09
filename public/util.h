#ifndef LC_UTIL_H
#define LC_UTIL_H

#include <string>

struct event_base;
struct timeval;
class Interface;

typedef void (*TimerFunc)(void *ctx);

class ITimer {
 public:
  virtual ~ITimer(void) {}

  virtual void* Add(timeval* tv, TimerFunc cb, void *ctx, bool persist = false) = 0;

  virtual void  Del(void* handle) = 0;
};

class IInterfaceSet {
 public:
  virtual ~IInterfaceSet(void) {}

  virtual Interface* Get(const std::string& if_name) = 0;

  virtual int Add(const std::string& if_name, Interface *interface) = 0;
};

class IEvent {
 public:
  virtual ~IEvent(void) {}

  virtual event_base* EventBase(void) = 0;
};

struct DroidInit {
  ITimer *timer;
  IInterfaceSet *if_set;
  IEvent *event;
};

#endif // LC_UTIL_H

