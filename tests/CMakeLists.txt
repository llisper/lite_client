add_library(test_droid SHARED test_droid.cc)
set_target_properties(test_droid PROPERTIES
  COMPILE_FLAGS ${cflags}
  PREFIX ""
  )
