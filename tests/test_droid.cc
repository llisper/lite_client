#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>

#include "use_dlog.h"
#include "public/droid.h"
#include "public/util.h"
#include "public/interface/interface.h"

static void TestTimer(void*);

class TestInterface : public Interface {
 public:
  virtual const std::string& name(void) = 0;
  virtual void set_name(const std::string& v) = 0;
};

class TestDroid : 
    public Droid,
    public TestInterface {
 public:
  virtual ~TestDroid(void) {}

  virtual int Init(DroidInit *dinit) {
    timer_ = dinit->timer;
    if_set_ = dinit->if_set;
    event_ = dinit->event;
    DLOG_INIT(dinit);

    DLOG("Init TestDroid");
    int retcode;
    // add a timer
    timeval tv = { 1, 0 };
    h_timer_ = timer_->Add(&tv, TestTimer, this, true);
    if (!h_timer_) 
      return -1;

    // add an interface
    if (0 != (retcode = if_set_->Add("TestI", this)))
      return retcode;

    return 0;
  }

  virtual int Destroy(void) {
    DLOG("Destroy TestDroid");
    timer_->Del(h_timer_);
    return 0;
  }

  void OnTimer(void) {
    TestInterface *test_i = (TestInterface*)if_set_->Get("TestI");
    assert(test_i);

    char name[6] = {0};
    for (int i = 0; i < 5; ++i)
      name[i] = (char)(rand() % 26 + 97);
    DLOG("OnTimer, get{%s}, set{%s}", test_i->name().c_str(), name);
    test_i->set_name(name);
  }

  virtual const std::string& name(void) { return name_; }
  virtual void set_name(const std::string& v) { name_ = v; }
 private:
  void *h_timer_;
  std::string name_;
  ITimer *timer_;
  IInterfaceSet *if_set_;
  IEvent *event_;
};

extern "C" Droid* onload(std::vector<const char*>& argv) {
  return new TestDroid;
}

extern "C" void unload(Droid* d) {
  delete d;
}

void TestTimer(void *ctx) {
  ((TestDroid*)ctx)->OnTimer();
}

