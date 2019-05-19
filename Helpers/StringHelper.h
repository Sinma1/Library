//
// Created by Sinma on 19.05.2019.
//

#ifndef BIBLIOTEKA_STRINGHELPER_H
#define BIBLIOTEKA_STRINGHELPER_H

#include <string>
#include <vector>
#include <sstream>

using std::string;

class StringHelper
{
public:
    std::vector<string> static Split(const string &text, const char &delimiter);
};


#endif //BIBLIOTEKA_STRINGHELPER_H
