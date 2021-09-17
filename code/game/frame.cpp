#include "frame.h"

namespace Sandbox {
    void Frame::Update() {
        _position += _velocity;
        _velocity *= 0.69f;

        // TODO: extend with drag coeff + collision detection
    }
} // namespace Sandbox
