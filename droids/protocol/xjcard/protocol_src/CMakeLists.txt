file(GLOB PROTO_SOURCE
    *.h *.cpp
    )

add_library(proto STATIC ${PROTO_SOURCE})
set_target_properties(proto
    PROPERTIES COMPILE_FLAGS ${cflags}
    )
