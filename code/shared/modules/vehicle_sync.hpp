#pragma once

#include <cstdint>

#include <flecs/flecs.h>

#include <glm/glm.hpp>

namespace Sandbox::Shared::Modules {
    struct VehicleSync {
        enum class LockState {
            Unlocked,
            Locked,
            Breakable,
        };

        struct UpdateData {
            glm::vec3 velocity{};
            glm::vec3 angularVelocity{};
            int gear = 0;
            bool horn = false;
            bool siren = false;
            bool beaconLights = false;
            float power = 0.0f;
            float brake = 0.0f;
            float handbrake = 0.0f;
            float steer = 0.0f;
            LockState locked = LockState::Unlocked;
            char licensePlate[7] = "";
        };

        VehicleSync(flecs::world& world) {
            world.module<VehicleSync>();

            world.component<UpdateData>();
        }
    };
}