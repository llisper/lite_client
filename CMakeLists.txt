cmake_minimum_required(VERSION 2.8)

project(lite_client)

set(cflags "-g -Wall")
set(3rd_parties ${CMAKE_SOURCE_DIR}/3rd_parties)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${3rd_parties}/include
    )

link_directories(${3rd_parties}/lib)

add_subdirectory(core)
add_subdirectory(droids)
add_subdirectory(tests)


#add_subdirectory(Proto)
#
#add_executable(lite_client
#    client.cc
#    )
#
#set_target_properties(lite_client
#    PROPERTIES COMPILE_FLAGS ${cflags}
#    )
#
#target_link_libraries(lite_client
#    proto
#    event
#    pthread
#    rt
#    )
#
