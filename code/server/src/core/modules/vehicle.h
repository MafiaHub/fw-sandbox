#pragma once

#include "core/server.h"
#include <flecs/flecs.h>

#include "shared/modules/vehicle_sync.hpp"

namespace Sandbox::Core::Modules {
    class Vehicle {
      public:
        struct CarData {
            uint64_t seats[4]{};
            Shared::Modules::VehicleSync::LockState locked = Shared::Modules::VehicleSync::LockState::Unlocked;
            std::string licensePlate = "M1-MP";
        };

        Vehicle(flecs::world &world);

        static flecs::entity Create(Sandbox::Server *server);

        static void SetupMessages(std::shared_ptr<Framework::World::ServerEngine> srv, Framework::Networking::NetworkServer *net);
    };
} // namespace Sandbox::Core::Modules