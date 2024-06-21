#include <iostream>
#include <csignal>
#include <thread>
#include "./inc/serverProcess/server.h"

Server* serverInstance = nullptr;

void signalHandlerWrapper(int signal) {
    if (serverInstance) {
        std::cout << "Signal " << signal << " received. Shutting down the server..." << std::endl;
        serverInstance->stop();
        std::cout << "Server stopped." << std::endl;
    }
    exit(signal);
}

int main() {
    Server server(8080);
    serverInstance = &server;
    server.start();

    std::signal(SIGINT, signalHandlerWrapper);
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
