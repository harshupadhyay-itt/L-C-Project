#include "../../inc/serverProcess/requestProcessor.h"
#include <iostream>
#include <vector>
#include "../../inc/DAO/userDAO.h"

RequestProcessor::RequestProcessor()
{
    std::cout << "processing request: 10\n";
    DatabaseConnection::initDbConnection("tcp://127.0.0.1:3306", "root", "root", "foodRecommendationDB");
    UserDAO *userDAO = new UserDAO();
    UserService *userService = new UserService(userDAO);
    this->authenticationController = new AuthenticationController(userService);
    // FeedbackDAO *feedbackDAO = new FeedbackDAO();
    // FeedbackService *feedbackService = new FeedbackService(feedbackDAO);
    // MenuItemDAO *menuItemDAO = new MenuItemDAO();
    // MenuItemService *menuItemService = new MenuItemService(menuItemDAO);
    // RecommendationEngine *recommendationEngine = new RecommendationEngine(feedbackService, menuItemService);
    // this->chefController = new ChefController(feedbackService, menuItemService, recommendationEngine);
}

std::vector<std::string> RequestProcessor::processRequest(std::vector<std::string> request)
{
    std::vector<std::string> response;
    bool userAuthenticated = false;
    std::cout << "processing request: 17\n";
    std::cout<<"43:"<<request[0]<<"\n";
    switch (std::stoi(request[0]))
    {
    case Operation::login:
    {
        std::cout << "processing request: 20 login \n";
        userAuthenticated = authenticationController->authenticateUser(std::stoi(request[1]), request[2]);
        std::cout << "processing request: userAuthenticated : " << userAuthenticated << "\n";
        // if (chefController)
        // {
            // auto vec = chefController->rolloutMenuForNextDay();

            // for(auto &i : vec){
            //     std::cout<<"---->"<<i<<"<----\n";
            // }
        // }
        if (userAuthenticated)
        {
            response = {"UserAuthenticated"};
        }
        else
        {
            response = {"User not Authenticated"};
        }
    }
    break;
    default:
        response = {"Invalid Operation"};
        break;
    }

    return response;
}