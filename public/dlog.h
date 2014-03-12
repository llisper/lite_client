#ifndef LC_DLOG_H
#define LC_DLOG_H

#include <cstddef>

class DLog {
 public:
  typedef void (*Sink)(const char* name, const char* log);

  DLog(void);
  DLog(const char* name, Sink sink);
  DLog(const DLog& rhs);
  DLog& operator=(const DLog& rhs);

  void Set(const char* name, Sink sink);

  void operator ()(const char *fmt, ...);

  Sink sink(void) const { return sink_; }
 private:
  enum { 
    BUFFSZ = 4096,
    NAMESZ = 32,
  };

  char name_[NAMESZ];
  char buffer_[BUFFSZ];
  char *ptr_;
  size_t log_size_;
  Sink sink_;
};

#endif // LC_DLOG_H

