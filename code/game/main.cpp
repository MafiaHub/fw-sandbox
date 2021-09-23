#include "compat.h"
#include "player.h"
#include "raylib.h"
#include "scenery.h"

#include <vector>

int main(void) {
    using namespace Sandbox;
    const int screenWidth  = 1600;
    const int screenHeight = 900;

    Camera3D camera   = {};
    camera.position   = {0.0f, 10.0f, 10.0f};
    camera.target     = {0.0f, 0.0f, 0.0f};
    camera.up         = {0.0f, 1.0f, 0.0f};
    camera.fovy       = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Scenery mission;
    Player player;

    InitWindow(screenWidth, screenHeight, "MafiaHub Sandbox game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        {
            // 1. Update player input
            {
                // TODO: Move into Camera class
                float x_axis = 0.0f;
                float y_axis = 0.0f;

                if (IsKeyDown(KEY_A))
                    x_axis -= 1.0f;
                if (IsKeyDown(KEY_D))
                    x_axis += 1.0f;
                if (IsKeyDown(KEY_W))
                    y_axis -= 1.0f;
                if (IsKeyDown(KEY_S))
                    y_axis += 1.0f;

                // TODO: scale vector to avoid faster diagonal movement
                // TODO: promote to Player::Move(x_axis,y_axis)
                constexpr float speed = 0.063f;
                player.AddForce({x_axis*speed, 0.0f, y_axis*speed});
            }
            // 2. Update all game actors
            {
                mission.Update();
                player.Update();

                // TODO: Design a Camera class with Camera::Follow() and Camera::Update() methods
                auto pos  = ConvertVector3(player.GetPosition());
                auto tgt = pos;
                pos.y += 15.0f;
                pos.z += 25.0f;
                camera.position = pos;

                tgt.z += 5.0f;
                camera.target = tgt;
            }

            // 3. Draw the scene
            BeginMode3D(camera);
            {
                // TODO: Design a frame list to iterate on
                mission.Draw();
                player.Draw();
            }
            EndMode3D();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
