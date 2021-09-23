#include "server.h"

int main() {
    Framework::Integrations::Server::InstanceOptions opts;
    opts.bindHost = "0.0.0.0";
    opts.bindPort = 27015;
    opts.bindName = "sandbox server";
    opts.maxPlayers = 10;
    opts.modName    = "Sandbox";
    opts.modSlug    = "sandbox_server";
    opts.modVersion = "0.1.0";
    opts.bindPassword = "";
    Sandbox::Server server;

    if (server.Init(opts) != Framework::Integrations::Server::ServerError::SERVER_NONE) {
        return 1;
    }

    while (server.IsAlive())
        server.Update();

    server.Shutdown();
    return 0;
}
