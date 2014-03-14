#ifndef LC_IDISPATCHER_H
#define LC_IDISPATCHER_H

#include "public/interface/interface.h"

class IDispatcher : public Interface {
 public:
  /**
   * @brief
   *  handler function
   */
  typedef int (*Handler)(void *message, void *ctx);

  /**
   * @brief
   *  subscribe a handler for a specific message id
   * @return
   *  0 - good
   *  < 0 - error 
   */
  virtual int Subscribe(int id, Handler handler, void *ctx) = 0;

  /**
   * @brief
   *  unsubscribe, delete the handler
   */
  virtual void Unsubscribe(int id) = 0;

  /**
   * @brief
   *  publish a message
   * @return
   *  error code from handler
   */
  virtual int Publish(int id, void *message) = 0;
};

#endif // LC_IDISPATCHER_H

