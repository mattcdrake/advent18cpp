#pragma once

#include <string>
#include <vector>

class day
{
protected:
    std::vector<std::string> input_lines_;

public:
    day();
    std::vector<std::string> parse_input_lines(const std::string& filepath) const;
    virtual std::string solve1() = 0;
    virtual std::string solve2() = 0;
};
