#pragma once

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Utilities
{
public:
    static std::string toLower(const std::string &str);
    static std::vector<std::string> splitWords(const std::string &str);
    static std::unordered_set<std::string> readWordsFromFile(const std::string &filename);
};