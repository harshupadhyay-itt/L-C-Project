#pragma once

#include <string>
#include <vector>
#include <netinet/in.h>
#include "vectorSerializer.h"

enum Operation : int {
   login = 0
};

class RequestHandler {
public:
    RequestHandler(int clientSocket, struct sockaddr_in serv_addr);
    void sendRequest(std::vector<std::string> request);
    std::vector<std::string> receiveResponse();
private:
    int clientSocket;
    struct sockaddr_in serv_addr;
    VectorSerializer vectorSerializer;
};
