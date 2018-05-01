//
// Created by Rasmus Munk on 15/04/2018.
//

#include "RobotServiceImpl.h"

using namespace std;
using namespace network;

// Add a robot to the simluation
grpc::Status RobotServiceImpl::Add(grpc::ServerContext *context, const network::Robot *robot,
                                   network::Response *response) {
    // TODO -> create robottype from factory
    string robot_type = "thymio2";
    auto type = _roboTypes.find(robot_type);
    const auto& creator(type->second.factory);
    auto instance(creator((unsigned)stoi(robot->config().port()), "thymio", type->second.prettyName,
                          (int16_t) robot->id()));
    auto new_robot(instance.robot);
    _world.addObject(new_robot);
    ++_num_spawned;
    //auto last_object = *_world.objects.end();
    return grpc::Status::OK;
}