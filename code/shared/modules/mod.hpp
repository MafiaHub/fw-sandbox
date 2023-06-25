#pragma once

#include <flecs/flecs.h>

namespace Sandbox::Shared::Modules {
    struct Mod {
        enum EntityTypes { MOD_PLAYER, MOD_VEHICLE };
        struct EntityKind {
            EntityTypes kind;
        };

        Mod(flecs::world &world) {
            world.module<Mod>();

            world.component<EntityKind>();
        }
    };
} // namespace Sandbox::Shared::Modules
