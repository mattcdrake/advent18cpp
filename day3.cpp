#include "day3.h"
#include "helpers.h"
#include <iostream>
#include <vector>

day3::day3()
{
    this->input_lines_ = parse_input_lines("input_data\\day3.txt");
    // Build fabric structure
    fabricTracker = new int*[1000];
}

day3::~day3()
{
    delete[] fabricTracker;
}

std::string day3::solve1()
{
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
    for (auto it = this->input_lines_.begin();
        it != this->input_lines_.end();
        ++it)
    {
        std::string line = *it;
        fabric_spec spec = buildFabricSpec(line);
        spec_tracker.push_back(spec);

        for (int i = spec.left_margin; i < spec.left_margin + spec.width; i++)
        {
            for (int j = spec.top_margin; j < spec.top_margin + spec.height; j++)
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

    return std::to_string(squares);
}

std::string day3::solve2()
{
    for (auto spec : spec_tracker)
    {
        if (is_free_spec(spec))
        {
            return std::to_string(spec.id);
        }
    }
    return "Unable to solve this puzzle.";
}

bool day3::is_free_spec(fabric_spec spec)
{
    for (auto i = spec.left_margin; i < spec.left_margin + spec.width; i++)
    {
        for (auto j = spec.top_margin; j < spec.top_margin + spec.height; j++)
        {
            if (fabricTracker[i][j] > 1)
            {
                return false;
            }
        }
    }
    return true;
}

day3::fabric_spec day3::buildFabricSpec(std::string input)
{
    fabric_spec output = { 0, 0, 0, 0, 0 };
    // Tokens: 0 - id, 1 - useless, 2 - left/top margins, 3 - width/height
    std::vector<std::string> tokens = splitString(input, ' ');

    // Omit the '#' char
    output.id = std::stoi(tokens[0].substr(1));

    int commaPos = tokens[2].find(',');
    output.left_margin = std::stoi(tokens[2].substr(0, commaPos));
    output.top_margin = std::stoi(tokens[2].substr(commaPos + 1));

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
