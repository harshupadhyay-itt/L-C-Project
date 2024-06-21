#include <iostream>
#include <vector>
#include <unordered_set>
#pragma once
class RecommendationEngine
{
public:
    struct MenuItem
    {
        std::string name;
        std::vector<std::string> foodItems;
        
    };

    // FeedbackService *feedbackService_{nullptr};
    // MenuItemService *menuItemService{nullptr};
    std::unordered_set<std::string> positiveWords_;
    std::unordered_set<std::string> negativeWords_;
    std::unordered_set<std::string> negationWords_;
    RecommendationEngine();
    // RecommendationEngine(FeedbackService* feedbackService);
    // RecommendationEngine(FeedbackService* feedbackService, MenuItemService* menuItemService);
    std::vector<std::string> recommendTopFoodItems();
    
    double evaluateFoodItem(const int &foodItem);
    double analyzeSentiment(const std::string &comment);
};
