#include "day3.h"
#include "helpers.h"
#include <iostream>
#include <vector>

day3::day3()
{
    this->input_lines_ = parse_input_lines("input_data\\day3.txt");
}

std::string day3::solve1()
{
    // Build fabric structure
    int** fabricTracker = new int*[1000];
    for (int i = 0; i < 1000; i++)
    {
        fabricTracker[i] = new int[1000];
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            fabricTracker[i][j] = 0;
        }
    }

    // Build a spec for each input data line, then add those positions to the fabricTracker
    for (std::vector<std::string>::iterator it = this->input_lines_.begin();
        it != this->input_lines_.end();
        it++)
    {
        std::string line = *it;
        FabricSpec spec = buildFabricSpec(line);

        for (int i = spec.leftMargin; i < spec.leftMargin + spec.width; i++)
        {
            for (int j = spec.topMargin; j < spec.topMargin + spec.height; j++)
            {
                fabricTracker[i][j]++;
            }
        }
    }

    // Determine answer (inches w/ two or more claims)
    int squares = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (fabricTracker[i][j] >= 2)
            {
                squares++;
            }
        }
    }

    delete[] fabricTracker;
    return std::to_string(squares);
}

std::string day3::solve2()
{
    return "Placeholder day 3 puzzle 2";
}

day3::FabricSpec day3::buildFabricSpec(std::string input)
{
    FabricSpec output = { 0, 0, 0, 0, 0 };
    // Tokens: 0 - id, 1 - useless, 2 - left/top margins, 3 - width/height
    std::vector<std::string> tokens = splitString(input, ' ');

    // Omit the '#' char
    output.id = std::stoi(tokens[0].substr(1));

    int commaPos = tokens[2].find(',');
    output.leftMargin = std::stoi(tokens[2].substr(0, commaPos));
    output.topMargin = std::stoi(tokens[2].substr(commaPos + 1));

    int xpos = tokens[3].find('x');
    output.width = std::stoi(tokens[3].substr(0, xpos));
    output.height = std::stoi(tokens[3].substr(xpos + 1));

    return output;
}

struct FabricSpec
{
    int id;
    int leftMargin;
    int topMargin;
    int width;
    int height;
};
