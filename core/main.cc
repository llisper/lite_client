#include "core.h"

#include <cstring>
#include <vector>

static void dlog_sink(const char* name, const char* log);

int main(int argc, char* argv[]) {
  Core core(dlog_sink);
  std::vector<const char*> arg_vector;
  for (int i = 1; i < argc; ++i)
    arg_vector.push_back(argv[i]);

  return core.Run(arg_vector);
}

void dlog_sink(const char* name, const char* log) {
  const char *color = "\e[0m";
  if (!strcmp(name, "core"))
    color = "\e[0;34m";
  else if (!strcmp(name, "test"))
    color = "\e[0;33m";
  else if (!strcmp(name, "net"))
    color = "\e[0;32m";

  fprintf(stdout, "%s%s\e[0m\n", color, log);
}
