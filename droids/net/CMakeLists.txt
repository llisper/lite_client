file(GLOB net_droid_sources
  RELATIVE ${CMAKE_CURRENT_LIST_DIR}
  *.cc
  )

use_dlog(net net_droid_sources)

set(public_sources
  ${CMAKE_SOURCE_DIR}/public/cbuf.cc
  ${CMAKE_SOURCE_DIR}/public/dlog.cc
  )

add_droid(net 
  ${net_droid_sources}
  ${public_sources}
  )

target_link_libraries(net
  event
  )

