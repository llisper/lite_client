#ifndef LC_DEBUG_LOG_H
#define LC_DEBUG_LOG_H

typedef void (*debug_log)(const char* log);
class DebugLog {
 public:
  DebugLog(void);

  void Set(debug_log l) { log_ = l; }

  void Log(const char* fmt, ...);
 private:
  enum { BUFFSZ = 4096 };
  char buffer[BUFFSZ];
  char *ptr;
  debug_log log_;
};

extern DebugLog g_debug_log;

#define DLOG_SET(log_func) g_debug_log.Set(log_func)
#define DLOG(fmt, ...) g_debug_log.Log(fmt, ##__VA_ARGS__)

#endif // LC_DEBUG_LOG_H

