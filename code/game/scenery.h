#pragma once
#include "frame.h"

namespace Sandbox {
    class Scenery final: public Frame {
      public:
        void Draw() override;
    };
} // namespace Sandbox
