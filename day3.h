#pragma once
#include "day.h"

class day3 :
    public day
{
public:
    day3();
    std::string solve1();
    std::string solve2();

    struct FabricSpec
    {
        int id;
        int leftMargin;
        int topMargin;
        int width;
        int height;
    };
    FabricSpec buildFabricSpec(std::string input);
};

