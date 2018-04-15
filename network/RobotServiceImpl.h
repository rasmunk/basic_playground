//
// Created by Rasmus Munk on 15/04/2018.
//

#ifndef PLAYGROUND_ROBOTSERVICEIMPL_H
#define PLAYGROUND_ROBOTSERVICEIMPL_H

#include <network/messages/simulation.ph.b>
//#include "../cmake-build-release/network/messages/simulation.grpc.pb.h"
#include <enki/PhysicalEngine.h>

class RobotServiceImpl final : public network::RobotService::Service
{
private:
    Enki::World& _world;

public:
    RobotServiceImpl(Enki::World& world) : _world(world) {};
    //grpc::Status Add(grpc::ServerContext*, const network::Robot*, network::Response*) override;
};


#endif //PLAYGROUND_ROBOTSERVICEIMPL_H
