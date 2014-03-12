#include "core.h"

#include <cassert>
#include <cstdio>
#include <vector>

static void dlog_sink(const char* name, const char* log);

int main(int argc, char* argv[]) {
  Core core(dlog_sink);
  std::vector<const char*> arg_vector;
  for (int i = 1; i < argc; ++i)
    arg_vector.push_back(argv[i]);

  return core.Run(arg_vector);
}

void dlog_output(const char* log) {
  fprintf(stdout, "\e[1;34m%s\e[0m\n", log);
}

void dlog_sink(const char* name, const char* log) {
  fprintf(stdout, "\e[1;34m%s\e[0m\n", log);
}
