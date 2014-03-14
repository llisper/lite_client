# include this directory at last so that the install command written below will
# be executed when all install process are completed
install(CODE "
  message(STATUS \"generate core.xml\")
  execute_process(
    COMMAND ${PYTHON_EXECUTABLE} \"${CMAKE_SOURCE_DIR}/gen_core_config.py\" ${CMAKE_INSTALL_PREFIX}
    WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}
    )")
