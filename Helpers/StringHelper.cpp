//
// Created by Sinma on 19.05.2019.
//

#include "StringHelper.h"

std::vector<string> StringHelper::Split(const string &text, const char &delimiter)
{
    std::vector<string> splitText;
    std::stringstream ss(text);

    std::string str;
    while (std::getline(ss, str, delimiter))
        splitText.push_back(str);

    return splitText;
}
