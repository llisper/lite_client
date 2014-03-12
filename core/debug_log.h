#ifndef LC_DEBUG_LOG_H
#define LC_DEBUG_LOG_H

#include "public/dlog.h"

extern DLog g_core_dlog;

#define DLOG_SET(name, log_sink) g_core_dlog.Set(name, log_sink)
#define DLOG(fmt, ...) g_core_dlog(fmt, ##__VA_ARGS__)

#endif // LC_DEBUG_LOG_H

