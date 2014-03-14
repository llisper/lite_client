set(codec_sources codec.cc)
use_dlog(codec codec_sources)

include_directories(${xjcard_root}/protocol)

add_droid(codec ${codec_sources})
target_link_libraries(codec xjcard_protocol)
