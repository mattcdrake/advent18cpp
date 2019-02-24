#pragma once

#include <string>
#include <vector>

class day
{
protected:
	std::vector<std::string> inputlines;

public:
	day();
	std::vector<std::string> parseInputLines(std::string filepath);
	virtual std::string solve1() = 0;
	virtual std::string solve2() = 0;
};

