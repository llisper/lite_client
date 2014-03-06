file(GLOB PROTO_SOURCE
    *.h *.cpp
    )

add_library(proto STATIC ${PROTO_SOURCE})
