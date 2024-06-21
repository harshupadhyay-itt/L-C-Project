#include "../../inc/service/recommendationEngineService.h"
#include "../../inc/utilities/utilities.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>

// RecommendationEngine::RecommendationEngine(FeedbackService *feedbackService, MenuItemService *menuItemService) : positiveWords_(Utilities::readWordsFromFile("../resource/PositiveWords.txt")),
//                                                                                                                  negativeWords_(Utilities::readWordsFromFile("../resouce/NegativeWords.txt")),
//                                                                                                                  negationWords_(Utilities::readWordsFromFile("../resource/NegationWords.txt"))
// {
//     feedbackService_ = feedbackService;
//     menuItemService = menuItemService;
// }

// std::vector<std::string> RecommendationEngine::recommendTopFoodItems()
// {
//     std::priority_queue<std::pair<double, int>> foodItemScores;
//     std::unordered_set<int> seenItems;
//     std::vector<int> ids;
//     auto menuItems = menuItemService->getAllMenuItems();
//     for (const auto &menuItem : menuItems)
//     {
//         ids.push_back(menuItem.menuItemId);
//     }
//     std::cout << "ids" << std::endl;
//     for (const auto &id : ids)
//     {
//         if (seenItems.find(id) == seenItems.end())
//         {
//             double score = evaluateFoodItem(id);
//             foodItemScores.push({score, id});
//             std::cout << "ids" << std::endl;
//             seenItems.insert(id);
//         }
//     }
//     std::cout << "ids" << std::endl;
//     std::vector<int> topFoodItemIds;
//     while (topFoodItemIds.size() < 4 && !foodItemScores.empty())
//     {
//         topFoodItemIds.push_back(foodItemScores.top().second);
//         foodItemScores.pop();
//     }
//     std::cout << "ids" << std::endl;
//     std::vector<std::string> topFoodItemName;
//     for (auto itemId : topFoodItemIds)
//     {
//         std::string itemName = menuItemService->getMenuItemById(itemId).menuItemName;
//         topFoodItemName.push_back(itemName);
//     }
//     return topFoodItemName;
// }

// double RecommendationEngine::evaluateFoodItem(const int &itemId)
// {
//     double totalScore = 0.0;

//     auto feedbacks = feedbackService_->getItemFeedbacks(itemId);
//     double averageSentimentScore = 0.0;
//     double averageRating = 0.0;
//     for (const auto &feedback : feedbacks)
//     {
//         averageSentimentScore += analyzeSentiment(feedback.comment);
//         averageRating += feedback.rating;
//     }

//     totalScore += (averageSentimentScore + averageRating) / feedbacks.size();

//     return totalScore;
// }

double RecommendationEngine::analyzeSentiment(const std::string &comment)
{
    std::string lowerComment = Utilities::toLower(comment);
    std::vector<std::string> words = Utilities::splitWords(lowerComment);

    int sentimentScore = 0;
    for (size_t index = 0; index < words.size(); ++index)
    {
        std::string word = words[index];
        bool isNegated = (index > 0 && negationWords_.find(words[index - 1]) != negationWords_.end());

        if (isNegated && index > 1 && negationWords_.find(words[index - 2]) != negationWords_.end())
        {
            isNegated = false;
        }

        if (positiveWords_.find(word) != positiveWords_.end())
        {
            sentimentScore += isNegated ? -1 : 1;
        }
        else if (negativeWords_.find(word) != negativeWords_.end())
        {
            sentimentScore += isNegated ? 1 : -1;
        }
    }

    if (sentimentScore > 1)
    {
        sentimentScore = 1;
    }
    else if (sentimentScore < -1)
    {
        sentimentScore = -1;
    }

    return ((sentimentScore + 1) / 2) * 5;
}
