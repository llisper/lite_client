include_directories(${CMAKE_SOURCE_DIR}/droids/xjcard/protocol)
add_executable(lite_client
    client.cc
    )

set_target_properties(lite_client
    PROPERTIES COMPILE_FLAGS ${cflags}
    )

target_link_libraries(lite_client
    event
    pthread
    rt
    xjcard_protocol
    )

