cmake_minimum_required(VERSION 2.8)

project(lite_client)

set(cflags "-g -Wall")
set(3rd_parties ${CMAKE_SOURCE_DIR}/3rd_parties)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${3rd_parties}/include
    )

link_directories(${3rd_parties}/lib)

macro(use_dlog m_name source_list)
    set(module_name ${m_name})
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    list(APPEND ${source_list} 
        ${CMAKE_CURRENT_BINARY_DIR}/use_dlog.h
        ${CMAKE_CURRENT_BINARY_DIR}/use_dlog.cc
        )

    configure_file(
        ${CMAKE_SOURCE_DIR}/public/config/use_dlog.h.conf
        ${CMAKE_CURRENT_BINARY_DIR}/use_dlog.h
        NEWLINE_STYLE UNIX
        )

    configure_file(
        ${CMAKE_SOURCE_DIR}/public/config/use_dlog.cc.conf
        ${CMAKE_CURRENT_BINARY_DIR}/use_dlog.cc
        NEWLINE_STYLE UNIX
        )
endmacro(use_dlog m_name)

add_subdirectory(core)
add_subdirectory(droids)
add_subdirectory(tests)

