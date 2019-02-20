#include "pch.h"
#include "day2.h"
#include <vector>
#include <unordered_map>

day2::day2()
{
  this->inputlines = parseInputLines("input_data\\day2.txt");
}

std::string day2::solve1()
{
  int twos = 0;
  int threes = 0;

  for (std::vector<std::string>::iterator it = this->inputlines.begin();
       it != this->inputlines.end(); it++)
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
  for (std::vector<std::string>::iterator it = this->inputlines.begin(); 
       it != this->inputlines.end(); it++)
  {
    std::string outerStr = *it;
    for (std::vector<std::string>::iterator it2 = it; 
         it2 != this->inputlines.end(); it2++) 
    {
      std::string innerStr = *it2;
      if (string_distance(outerStr, innerStr))
      {
        return strip_different(outerStr, innerStr);
      }
    }
  }

  return "Answer not found.";
}

bool day2::hasN(std::string word, int n)
{
  std::unordered_map<char, int> letters;

  for (size_t i = 0; i < word.length(); i++) 
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

// Returns true if strings are only 1 character apart (but same length)
bool day2::string_distance(std::string string1, std::string string2) 
{
  // Exit early if strings aren't the same length
  if (string1.length() != string2.length()) 
  {
    return false;
  }

  int distance = 0;
  
  for (size_t i = 0; i < string1.length(); i++) 
  {
    if (string1[i] != string2[i]) 
    {
      distance++;
    }
    if (distance > 1) 
    {
      return false;
    }
  }
  
  return distance == 1;
}

// Returns a string with all differing characters (between the two strings)
// stripped out, or empty string if they have differing lengths.
std::string day2::strip_different(std::string string1, std::string string2) 
{
  std::string outStr = "";
  if (string1.length() != string2.length()) 
  {
    return outStr;
  }

  for (size_t i = 0; i < string1.length(); i++) 
  {
    if (string1[i] == string2[i]) 
    {
      outStr += string1[i];
    }
  }

  return outStr;
}

