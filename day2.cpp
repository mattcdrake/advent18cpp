#include "pch.h"
#include "day2.h"
#include <vector>
#include <unordered_map>

day2::day2()
{
  this->inputlines = parseInputLines("input_data\\day2.txt");
}

day2::~day2()
{
}

std::string day2::solve1()
{
  int twos = 0;
  int threes = 0;

  for (std::vector<std::string>::iterator it = this->inputlines.begin(); it != this->inputlines.end(); it++) 
  {
    std::string line = *it;
    if (hasN(line, 2)) 
    {
      twos++;
    }
    if (hasN(line, 3)) 
    {
      threes++;
    }
  }
  return std::to_string(twos * threes);
}

std::string day2::solve2()
{
  return "TEMP";
}

bool day2::hasN(std::string word, int n)
{
  std::unordered_map<char, int> letters;

  for (unsigned i = 0; i < word.length(); i++) 
  {
    if (letters.find(word[i]) != letters.end()) 
    {
      letters.at(word[i])++;
    }
    else 
    {
      letters[word[i]] = 1;
    }
  }
  
  for (std::unordered_map<char, int>::iterator it = letters.begin(); it != letters.end(); it++)
  {
    if (it->second == n)
    {
      return true;
    }
  }
  return false;
}
