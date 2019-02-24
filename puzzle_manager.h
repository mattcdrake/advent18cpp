#pragma once

#include <map>

class puzzle_manager
{
private:
    std::map<int, std::string> solutions;

public:
    puzzle_manager();
    void printSolutions();
};
