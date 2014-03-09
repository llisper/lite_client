#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>

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
    printf("Init TestDroid\n");
    dinit_ = dinit;
    int retcode;
    // add a timer
    timeval tv = { 1, 0 };
    h_timer_ = dinit_->timer->Add(&tv, TestTimer, this, true);
    if (!h_timer_) 
      return -1;

    // add an interface
    if (0 != (retcode = dinit_->if_set->Add("TestI", this)))
      return retcode;

    return 0;
  }

  virtual int Destroy(void) {
    printf("Destroy TestDroid\n");
    dinit_->timer->Del(h_timer_);
    return 0;
  }

  void OnTimer(void) {
    TestInterface *test_i = (TestInterface*)dinit_->if_set->Get("TestI");
    assert(test_i);

    char name[6] = {0};
    for (int i = 0; i < 5; ++i)
      name[i] = (char)(rand() % 26 + 97);
    printf("OnTimer, get{%s}, set{%s}\n", test_i->name().c_str(), name);
    test_i->set_name(name);
  }

  virtual const std::string& name(void) { return name_; }
  virtual void set_name(const std::string& v) { name_ = v; }
 private:
  DroidInit *dinit_;
  void *h_timer_;
  std::string name_;
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

