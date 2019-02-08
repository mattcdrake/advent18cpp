#include "pch.h"
#include "day1.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>

day1::day1()
{
  this->inputlines = parseInputLines("input_data\\day1.txt");
}

day1::~day1()
{
}

// TODO: Make a helper function that converts the string vector to an int vector
//       and adjust algorithms accordingly. Hopefully this will speed up the
//       abysmal performance.
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
  std::set<int> seenVals;
  std::vector<std::string>::iterator it = this->inputlines.begin();


  // Input file is looped 144 times
  while (!exitLoop)
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
    if (it == inputlines.end())
    {
      it = inputlines.begin();
    }
  }
  return output;
}
