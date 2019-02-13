#pragma once
#include "day.h"
class day2 :
  public day
{
public:
  day2();
  ~day2();
  std::string solve1();
  std::string solve2();
  bool hasN(std::string word, int num);
};

