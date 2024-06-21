#include <iostream>
#include <csignal>
#include "./inc/client.h"
#include "./inc/clientController.h"

Client * clientInstance = nullptr;
void clientHandlerWrapper(int signal) {
    clientInstance->disconnect();  
    exit(signal);
}

int main() {
    int server_port = 8080;

    Client client(server_port);
    ClientController clientController(client);
    clientController.start();
    clientInstance = &client;
    std::signal(SIGINT, clientHandlerWrapper);

    return 0;
}
