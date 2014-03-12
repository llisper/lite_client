file(GLOB net_droid_sources
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    *.cc
    )

set(public_sources
    ${CMAKE_SOURCE_DIR}/public/cbuf.cc
    )

add_library(net_droid SHARED 
    ${net_droid_sources}
    ${public_sources}
    )

target_link_libraries(net_droid
    event
    )

set_target_properties(net_droid PROPERTIES
  COMPILE_FLAGS "${cflags} -fPIC"
  PREFIX ""
  )


