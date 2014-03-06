cmake_minimum_required(VERSION 2.8)

set(cflags "-Wall")
include_directories(${CMAKE_SOURCE_DIR}/../install/include)
link_directories(${CMAKE_SOURCE_DIR}/../install/lib)

add_subdirectory(Proto)

add_executable(lite_client
    main.cc
    )

set_target_properties(lite_client
    PROPERTIES COMPILE_FLAGS ${cflags}
    )

target_link_libraries(lite_client
    pthread
    event
    proto
    )

