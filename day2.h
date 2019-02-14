#pragma once
#include "day.h"
class day2 :
  public day
{
public:
  day2();
  std::string solve1();
  std::string solve2();
  bool hasN(std::string word, int num);
  bool string_distance(std::string string1, std::string string2);
  std::string strip_different(std::string string1, std::string string2);
};

