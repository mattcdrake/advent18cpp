#include "pch.h"
#include "day1.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>

day1::day1()
{
	this->inputlines = parseInputLines("input_data\\day1.txt");
}

std::string day1::solve1()
{
	int runningTotal = 0;
	for (std::vector<std::string>::iterator it = this->inputlines.begin(); it != this->inputlines.end(); it++)
	{
		std::string line = *it;
		if (line.length() > 1)
		{
			if (line[0] == '+')
			{
				runningTotal += std::stoi(line.substr(1, std::string::npos));
			}
			else if (line[0] == '-')
			{
				runningTotal -= std::stoi(line.substr(1, std::string::npos));
			}
		}
	}
	return std::to_string(runningTotal);
}

std::string day1::solve2()
{
	// Priming the loop
	bool exitLoop = false;
	std::string output = "";
	int runningTotal = 0;
	std::unordered_set<int> seenVals;

	// Convert string vector to an int vector
	std::list<int> inputvals;

	for (std::vector<std::string>::iterator sit = this->inputlines.begin(); sit != this->inputlines.end(); sit++)
	{
		std::string line = *sit;

		if (line.length() > 1)
		{
			if (line[0] == '+')
			{
				inputvals.push_back(std::stoi(line.substr(1, std::string::npos)));
			}
			else if (line[0] == '-')
			{
				inputvals.push_back(-1 * std::stoi(line.substr(1, std::string::npos)));
			}
		}
	}

	std::list<int>::iterator it = inputvals.begin();

	while (!exitLoop)
	{
		runningTotal += *it;

		// Exit if the current frequency has been seen before, otherwise add it
		if (seenVals.find(runningTotal) != seenVals.end())
		{
			output = std::to_string(runningTotal);
			exitLoop = true;
		}
		else
		{
			seenVals.insert(runningTotal);
		}

		it++;
		if (it == inputvals.end())
		{
			it = inputvals.begin();
		}
	}
	return output;
}
