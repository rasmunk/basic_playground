# compile protobuf/grpc dependencies
add_subdirectory(messages)

# Use them in actual impl
set(SOURCE
        GrpcServer.h
        GrpcServer.cpp
        RobotServiceImpl.h
        RobotServiceImpl.cpp)

add_library(network ${SOURCE})

install(TARGETS network
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR})
