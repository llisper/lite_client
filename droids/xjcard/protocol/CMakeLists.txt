file(GLOB protocol_sources
  RELATIVE ${CMAKE_CURRENT_LIST_DIR}
  *.cpp
  )

add_library(xjcard_protocol STATIC ${protocol_sources})
set_target_properties(xjcard_protocol PROPERTIES
  COMPILE_FLAGS "${cflags} -fPIC"
  )
