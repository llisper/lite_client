#ifndef LC_CBUF_H
#define LC_CBUF_H

#include <cstddef>

class CBuf {
 public:
  CBuf(void);
  ~CBuf(void);

  /* give out the pointer pointing to internal buffer
   * won't work if cbuf is access by mutiple clients simultaneously
   */
  const char* Sniff(size_t& sz) const;

  int Drain(size_t sz);

  int Push(const char* dptr, size_t sz);

  size_t Size(void) const { return wpos_ - rpos_; }
 private:
  char* buf_;
  size_t rpos_;
  size_t wpos_;
  size_t capacity_;
};

#endif // LC_CBUF_H

