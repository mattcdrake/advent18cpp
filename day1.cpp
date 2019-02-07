#include "pch.h"
#include "day1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

day1::day1()
{
  this->inputlines = parseInputLines("input_data\\day1.txt");
}

day1::~day1()
{
}

std::string day1::solve1()
{

  int runningTotal = 0;
  for (std::vector<std::string>::iterator it = inputlines.begin(); it != inputlines.end(); it++)
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
  return "test2";
}
