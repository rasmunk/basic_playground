set(SOURCE
        GrpcServer.h
        GrpcServer.cpp
        RobotServiceImpl.h
        RobotServiceImpl.cpp)

add_library(network ${SOURCE})

install(TARGETS network
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR})

add_subdirectory(messages)