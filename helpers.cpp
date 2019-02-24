#include "helpers.h"
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitString(std::string input, char delim)
{
    std::vector<std::string> output;
    std::istringstream ss(input);
    std::string token;

    while (!ss.eof())
    {
        std::getline(ss, token, ' ');
        output.push_back(token);
    }

    return output;
}
