//
// Created by Rasmus Munk on 15/04/2018.
//

#include "RobotServiceImpl.h"

using namespace std;

// Add a robot to the simluation
grpc::Status RobotServiceImpl::Add(grpc::ServerContext *, const network::Robot *,
                                   network::Response *) {

    // TODO -> create robottype from factory
    const auto& creator(_roboTypes);

    return grpc::Status::OK;
}