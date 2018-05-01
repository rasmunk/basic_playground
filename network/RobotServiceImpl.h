//
// Created by Rasmus Munk on 15/04/2018.
//

#ifndef PLAYGROUND_ROBOTSERVICEIMPL_H
#define PLAYGROUND_ROBOTSERVICEIMPL_H

#include <network/messages/simulation.grpc.pb.h>
#include <enki/PhysicalEngine.h>
#include "../sim/Robots.h"



class RobotServiceImpl final : public network::RobotService::Service
{
private:
    unsigned int _num_spawned;
    Enki::World& _world;
    std::map<std::string, Enki::RobotType>& _roboTypes;

public:
    RobotServiceImpl(Enki::World &world, std::map<std::string, Enki::RobotType> &roboTypes) :
            _world(world), _roboTypes(roboTypes) {};

    grpc::Status Add(grpc::ServerContext *, const network::Robot *, network::Response *) override;
};


#endif //PLAYGROUND_ROBOTSERVICEIMPL_H
