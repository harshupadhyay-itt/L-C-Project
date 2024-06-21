#pragma once

#include <string>
#include <vector>
#include "../controller/authenticationController.h"
#include "../controller/chefController.h"


enum Operation : int {
   login = 0
};

class RequestProcessor
{
private:
    AuthenticationController *authenticationController;
    // ChefController *chefController;

public:
    RequestProcessor();
    std::vector<std::string> processRequest(std::vector<std::string> request);
};
