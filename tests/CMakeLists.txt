set(source_list test_droid.cc)
use_dlog(test_droid source_list)

add_library(test_droid SHARED ${source_list})
set_target_properties(test_droid PROPERTIES
  COMPILE_FLAGS ${cflags}
  PREFIX ""
  )
