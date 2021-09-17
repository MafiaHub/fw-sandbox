#pragma once
#include "frame.h"

namespace Sandbox {
    class Player final: public Frame {
      public:
        Player() = default;
        void Draw() override;
    };
} // namespace Sandbox
