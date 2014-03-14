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

macro(r_add_dirs)
  file(GLOB cmakelists
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    */CMakeLists.txt
    )

  foreach(ml ${cmakelists})
    get_filename_component(dir ${ml} PATH)
    add_subdirectory(${dir})
  endforeach(ml ${cmakelists})
endmacro(r_add_dirs)

macro(add_droid target_name)
  add_library(${target_name} SHARED ${ARGN})
  set_target_properties(${target_name} PROPERTIES 
    COMPILE_FLAGS ${cflags}
    PREFIX ""
    )
endmacro(add_droid target_name)
