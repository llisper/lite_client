#include "cbuf.h"
#include <cstring>

#define INIT_SIZE 4096
#define LEFT_THRESHOLD 32

static char* extend(char* buf, size_t& r, size_t& w, size_t new_size);

CBuf::CBuf(void) {
  buf_ = new char[INIT_SIZE];
  capacity_ = INIT_SIZE;
  rpos_ = wpos_ = 0;
}

CBuf::~CBuf(void) {
  delete [] buf_;
}

const char* CBuf::Sniff(size_t& sz) const {
  sz = wpos_ - rpos_;
  return &buf_[rpos_];
}

int CBuf::Drain(size_t sz) {
  if (Size() < sz)
    return -1;
  rpos_ += sz;
  return 0;
}

int CBuf::Push(const char* dptr, size_t sz) {
  if (capacity_ < wpos_ + sz) {
    if (capacity_ - Size() < LEFT_THRESHOLD) {
      size_t new_capacity = (size_t)(capacity_ * 1.5);
      char* new_buf = extend(buf_, rpos_, wpos_, new_capacity);
      delete buf_;
      buf_ = new_buf;
      capacity_ = new_capacity;
    } else {
      extend(buf_, rpos_, wpos_, 0);
    }
  }

  memcpy(buf_ + wpos_, dptr, sz);
  wpos_ += sz;
  return 0;
}

char* extend(char* buf, size_t& r, size_t& w, size_t new_size) {
  char* new_buf = new_size ? new char[new_size] : buf;
  size_t old_size = w - r;
  memmove(new_buf, buf + r, old_size); 
  r = 0;
  w = old_size;
  return new_buf;
}

#undef INIT_SIZE
#undef LEFT_THRESHOLD

