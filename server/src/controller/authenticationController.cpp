#include "../../inc/controller/authenticationController.h"
#include <iostream>

AuthenticationController::AuthenticationController(UserService *userService)
    : userService(userService) {}

bool AuthenticationController::authenticateUser(const int &userId, const std::string &password)
{
    return userService->authenticateUser(userId, password);
}
