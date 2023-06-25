#include "environment.h"

namespace Sandbox::Core::Modules {
    Environment::Environment(flecs::world& world) {
        world.module<Environment>();
        world.component<Weather>();
    }
}
