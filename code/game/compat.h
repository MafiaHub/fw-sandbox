#pragma once
#include <glm/glm.hpp>
#include <raylib.h>

namespace Sandbox {
    inline Vector3 ConvertVector3(const glm::vec3 &rhs) {
        return {rhs.x, rhs.y, rhs.z};
    }
} // namespace Sandbox
