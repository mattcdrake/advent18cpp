#include "pch.h"
#include "dayWrapper.h"
#include "puzzlemanager.h"
#include <iostream>
#include <string>

puzzlemanager::puzzlemanager()
{
  day1 day_1 = day1();
  solutions.insert(std::pair<int, std::string>(1, day_1.solve1()));
  solutions.insert(std::pair<int, std::string>(2, day_1.solve2()));

  day2 day_2 = day2();
  solutions.insert(std::pair<int, std::string>(3, day_2.solve1()));
  solutions.insert(std::pair<int, std::string>(4, day_2.solve2()));
}

puzzlemanager::~puzzlemanager()
{
}

void puzzlemanager::printSolutions()
{
  std::cout << "Solutions to Advent of Code 2018 Puzzles" << std::endl;

  int puzzleCount = 1;

  for (std::map<int, std::string>::iterator it = solutions.begin(); it != solutions.end(); it++)
  {
    std::cout << "Solution #" << puzzleCount << ": " << it->second << std::endl;
    puzzleCount++;
  }
}
