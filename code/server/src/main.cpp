#include "core/server.h"

int main(int argc, char **argv) {
    Framework::Integrations::Server::InstanceOptions opts;
    opts.bindHost      = "0.0.0.0";
    opts.bindPort      = 27015;
    opts.webBindHost   = "0.0.0.0";
    opts.webBindPort   = 27016;
    opts.bindName      = "Sandbox Local Dev Server";
    opts.maxPlayers    = 10;
    opts.modName       = "Sandbox";
    opts.modSlug       = "sandbox_server";
    opts.gameName      = "MafiaHub: Sandbox";
    opts.gameVersion   = "1.0.0";
    opts.modVersion    = "0.1.0";
    opts.bindPassword  = "";
    opts.enableSignals = true;

    opts.argc = argc;
    opts.argv = argv;

    opts.firebaseEnabled   = true;
    opts.firebaseProjectId = "mafiahub-3ebed";
    opts.firebaseAppId     = "1:546323083920:web:6716980a4d6412e87e1e15";
    opts.firebaseApiKey    = "AIzaSyBwcNaneu4K17RaLbACw18teTi1G0QpJkw";

    Sandbox::Server server;
    if (server.Init(opts) != Framework::Integrations::Server::ServerError::SERVER_NONE) {
        return 1;
    }
    server.Run();
    server.Shutdown();
    return 0;
}
