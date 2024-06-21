#include "../inc/clientController.h"
#include <iostream>

#include<vector>

ClientController::ClientController(Client& client)
    : client(client), requestHandler(nullptr) {}

void ClientController::start() {
    if (!client.connectToServer()) {
        std::cerr << "Failed to connect to server" << std::endl;
        return;
    }

    requestHandler = new RequestHandler(client.getSocket(), client.getAddress());
    handleUserInput();

    delete requestHandler;
    client.disconnect();
}

void ClientController::handleUserInput() {
    int userId;
    std::string password;
    std::cout << "Enter Credantials: \n";
    std::cout<<"UserId : ";
    std::cin>>userId;
    std::cout<<"Password : ";
    std::cin>>password;

    requestHandler->sendRequest({std::to_string(Operation::login), std::to_string(userId), password} ) ;
    std::vector<std::string> response = requestHandler->receiveResponse();
    std::cout << "Server: " << response[0]<< std::endl;
}
