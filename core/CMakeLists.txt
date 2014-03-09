file(GLOB CORE_SOURCE
  *.h *.cc
  )

add_executable(core ${CORE_SOURCE})

set_target_properties(core PROPERTIES 
  COMPILE_FLAGS ${cflags}
  LINK_FLAGS "-Wl,--no-as-need -lrt" # for linux at home :)
  )

target_link_libraries(core
  dl
  event
  expat
  )
