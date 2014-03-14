#include "use_dlog.h"
#include "public/droid.h"
#include "public/util.h"
#include "public/export.h"
#include "public/interface/net.h"
#include "public/interface/interface.h"

#include <arpa/inet.h>

class TestNet : public Droid {
 public:
  virtual ~TestNet(void) {}

  virtual int Init(void) {
    DLOG_INIT(util());

    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = 9995;
    inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr);

    Interface *interface = util()->if_set->Get("INet");
    INet *net = (INet*)interface;
      
    int retcode = net->OpenSession(&sin, OpenCB, this);
    if (0 != retcode) {
      DLOG("open session failed");
    }

    return 0;
  }

  virtual int Destroy(void) {
    return 0;
  }

  static void OpenCB(ssize_t sid, void *ctx) {
    if (sid < 0) 
      DLOG("invalid sid");
    else
      DLOG("connected");
  }
};

EXPORT_DROID_NOARG(TestNet);

