file(GLOB proto_sources
  ../droids/protocol/xjcard/protocol_src/*.cpp
  )

include_directories(../droids/protocol/xjcard/protocol_src)
message(STATUS ${proto_sources})

add_executable(lite_client
    client.cc
    ${proto_sources}
    )

set_target_properties(lite_client
    PROPERTIES COMPILE_FLAGS ${cflags}
    )

target_link_libraries(lite_client
    event
    pthread
    rt
    )

