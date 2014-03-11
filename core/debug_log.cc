#include "debug_log.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>

DebugLog g_debug_log;

DebugLog::DebugLog(void) : log_(NULL) {
  strcpy(buffer, "[dlog]: ");
  ptr = buffer + strlen("[dlog]: ");
}

void DebugLog::Log(const char* fmt, ...) {
  if (log_) {
    va_list vl;
    va_start(vl, fmt);
    int n = vsnprintf(ptr, BUFFSZ, fmt, vl);
    va_end(vl);
    if (n > 0) {
      log_(buffer);
    }
  }
}

