#pragma once

#include "client.h"
#include "requestHandler.h"

class ClientController {
public:
    ClientController(Client& client);
    void start();

private:
    Client& client;
    RequestHandler* requestHandler;

    void handleUserInput();
};
