#include "../../inc/service/userService.h"
#include <iostream>

UserService::UserService(IUserDAO *userDAO)
    : userDAO(userDAO) {}

bool UserService::addUser(const User &user)
{
    return userDAO->addUser(user);
}

bool UserService::deleteUserByID(int userId)
{
    return userDAO->deleteUser(userId);
}

User UserService::getUserById(int userId)
{
    return userDAO->getUserByID(userId);
}

std::vector<User> UserService::getAllUsers()
{
    return userDAO->getAllUsers();
}

bool UserService::authenticateUser(const int &userId, const std::string &password)
{
    User user = userDAO->getUserByID(userId);
    return user.password == password;
}
