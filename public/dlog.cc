#include "dlog.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>

DLog::DLog(void) : ptr_(NULL), log_size_(0), sink_(NULL) {}

DLog::DLog(const char* name, Sink sink) {
  Set(name, sink);
}

DLog::DLog(const DLog& rhs) {
  strncpy(name_, rhs.name_, NAMESZ);
  sink_ = rhs.sink_;
  int len = sprintf(buffer_, "[%s]: ", name_);
  ptr_ = buffer_ + len;
  log_size_ = BUFFSZ - len;
}

DLog& DLog::operator=(const DLog& rhs) {
  strncpy(name_, rhs.name_, NAMESZ);
  sink_ = rhs.sink_;
  int len = sprintf(buffer_, "[%s]: ", name_);
  ptr_ = buffer_ + len;
  log_size_ = BUFFSZ - len;
  return *this;
}

void DLog::Set(const char* name, Sink sink) {
  strncpy(name_, name, NAMESZ);
  sink_ = sink;
  int len = sprintf(buffer_, "[%s]: ", name_);
  ptr_ = buffer_ + len;
  log_size_ = BUFFSZ - len;
}

void DLog::operator()(const char *fmt, ...) {
  if (sink_) {
    va_list vl;
    va_start(vl, fmt);
    int n = vsnprintf(ptr_, log_size_, fmt, vl);
    va_end(vl);
    if (n > 0) {
      sink_(name_, buffer_);
    }
  }
}
