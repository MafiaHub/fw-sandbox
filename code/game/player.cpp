#include "player.h"

#include "compat.h"

#include <raylib.h>

namespace Sandbox {
    void Player::Draw() {
        const auto pos = ConvertVector3(GetPosition());
        DrawSphere(pos, 1.0f, RED);
    }
} // namespace Sandbox
