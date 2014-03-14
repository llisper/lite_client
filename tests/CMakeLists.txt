use_dlog(test_droid test_dlog_cc)

add_droid(test_droid 
  test_droid.cc
  ${test_dlog_cc}
  )

add_executable(echo_svr echo_svr.cc)
target_link_libraries(echo_svr event rt)

add_droid(test_net
  test_net.cc
  ${test_dlog_cc}
  )
