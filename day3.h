#pragma once
#include "day.h"
#include <vector>

class day3 :
    public day
{
public:
    struct fabric_spec
    {
        int id;
        int left_margin;
        int top_margin;
        int width;
        int height;
    };
    int** fabricTracker;
    std::vector<fabric_spec> spec_tracker;

    day3();
    ~day3();
    std::string solve1();
    std::string solve2();
    fabric_spec buildFabricSpec(std::string input);
    bool is_free_spec(day3::fabric_spec spec);
};

