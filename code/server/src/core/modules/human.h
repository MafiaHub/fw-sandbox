#pragma once

#include "core/server.h"
#include <flecs/flecs.h>

namespace Sandbox::Core::Modules {
    class Human {
      public:
        Human(flecs::world &world);

        static void Create(Framework::Networking::NetworkServer *net, flecs::entity e);

        static void SetupMessages(std::shared_ptr<Framework::World::ServerEngine> srv, Framework::Networking::NetworkServer *net);

        private:
        static void InitRPCs(std::shared_ptr<Framework::World::ServerEngine> srv, Framework::Networking::NetworkServer *net);
    };
} // namespace Sandbox
