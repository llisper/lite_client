file(GLOB cmakelists
  RELATIVE ${CMAKE_CURRENT_LIST_DIR}
  */CMakeLists.txt
  )

foreach(ml ${cmakelists})
  get_filename_component(dir ${ml} PATH)
  add_subdirectory(${dir})
endforeach(ml ${cmakelists})
