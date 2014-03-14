cmake_minimum_required(VERSION 2.8)

project(lite_client)

set(cflags "-g -Wall")
set(3rd_parties ${CMAKE_SOURCE_DIR}/3rd_parties)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/stage)

find_package(PythonInterp REQUIRED)

include(cmake/common.cmake)

include_directories(
  ${CMAKE_SOURCE_DIR}
  ${3rd_parties}/include
  )

link_directories(${3rd_parties}/lib)

add_subdirectory(core)
add_subdirectory(droids)
add_subdirectory(tests)
add_subdirectory(backup)
add_subdirectory(post_install)
