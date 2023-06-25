#pragma once

#include "scripting/engines/node/engine.h"
#include "scripting/engines/node/sdk.h"

#include "../modules/environment.h"
#include "../modules/vehicle.h"

#include "shared/rpc/chat_message.h"

#include "vehicle.h"
#include "player.h"

#include "core_modules.h"

namespace Sandbox::Scripting {
    class World final {
      public:
        static v8::Local<v8::Object> WrapVehicle(v8::Isolate *isolate, flecs::entity e) {
            return v8pp::class_<Scripting::Vehicle>::create_object(isolate, e.id());
        }

        static v8::Local<v8::Object> CreateVehicle(v8::Isolate *isolate, std::string modelName) {
            auto e = Sandbox::Core::Modules::Vehicle::Create(Server::_serverRef);

            auto frame       = e.get_mut<Framework::World::Modules::Base::Frame>();
            frame->modelName = modelName;

            return WrapVehicle(isolate, e);
        }

        static void SendChatMessage(std::string message, Human *human) {
            if (human) {
                const auto ent = human->GetHandle();
                const auto str   = ent.get<Framework::World::Modules::Base::Streamer>();
                if (!str)
                    return;
                FW_SEND_COMPONENT_RPC_TO(Shared::RPC::ChatMessage, SLNet::RakNetGUID(str->guid), message);
            }
        }

        static void BroadcastMessage(std::string message) {
            FW_SEND_COMPONENT_RPC(Shared::RPC::ChatMessage, message);
        }

        static void OnChatMessage(flecs::entity e, std::string message) {
            Framework::CoreModules::GetScriptingModule()->ForEachResource([&](Framework::Scripting::Engines::IResource *resource) {
                auto nodeResource = reinterpret_cast<Framework::Scripting::Engines::Node::Resource *>(resource);
                nodeResource->InvokeEvent("chatMessage", Human::WrapHuman(nodeResource, e), message);
            });
        }

        static void OnChatCommand(flecs::entity e, std::string message, std::string command, std::vector<std::string> args) {
            Framework::CoreModules::GetScriptingModule()->ForEachResource([&](Framework::Scripting::Engines::IResource *resource) {
                auto nodeResource = reinterpret_cast<Framework::Scripting::Engines::Node::Resource *>(resource);
                nodeResource->InvokeEvent("chatCommand", Human::WrapHuman(nodeResource, e), message, command, args);
            });
        }

        static void Register(v8::Isolate *isolate, v8pp::module *rootModule) {
            // Create the vehicle namespace
            v8pp::module world(isolate);
            world.function("createVehicle", &World::CreateVehicle);
            rootModule->submodule("World", world);

            rootModule->function("sendChatMessage", &World::SendChatMessage);
            rootModule->function("broadcastMessage", &World::BroadcastMessage);
        }
    };
} // namespace Sandbox::Scripting
