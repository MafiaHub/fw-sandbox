#pragma once
#include <glm/glm.hpp>

namespace Sandbox {
    class Frame {
      protected:
        glm::vec3 _position = {0.0f, 0.0f, 0.0f};
        glm::vec3 _direction = {0.0f, 0.0f, 0.0f};
        glm::vec3 _velocity = {0.0f, 0.0f, 0.0f};

      public:
        Frame() = default;

        Frame(const Frame &rhs) {
            _position = rhs._position;
            _direction = rhs._direction;
        }

        Frame &operator=(const Frame &rhs) {
            _position = rhs._position;
            _direction = rhs._direction;
        }

        glm::vec3 GetPosition() const {
            return _position;
        }

        void SetPosition(glm::vec3 position) {
            _position = position;
        }

        glm::vec3 GetDirection() const {
            return _direction;
        }

        void SetDirection(glm::vec3 direction) {
            _direction = direction;
        }

        glm::vec3 GetVelocity() const {
            return _velocity;
        }

        void SetVelocity(glm::vec3 velocity) {
            _velocity = velocity;
        }

        void AddForce(glm::vec3 force) {
            _velocity += force;
        }

        virtual void Draw() = 0;

        virtual void Update();
    };
} // namespace Sandbox
