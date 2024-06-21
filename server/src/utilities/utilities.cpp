#include "../../inc/utilities/utilities.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::string Utilities::toLower(const std::string &inputString)
{
    std::string lowerString = inputString;
    std::transform(lowerString.begin(), lowerString.end(), lowerString.begin(), ::tolower);
    return lowerString;
}

std::vector<std::string> Utilities::splitWords(const std::string &inputString)
{
    std::vector<std::string> words;
    std::string word;
    for (char character : inputString)
    {
        if (std::isspace(character))
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += character;
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    return words;
}

std::unordered_set<std::string> Utilities::readWordsFromFile(const std::string &filename)
{
    std::unordered_set<std::string> words;
    std::ifstream file(filename);
    std::string word;
    while (file >> word)
    {
        words.insert(word);
    }
    return words;
}
