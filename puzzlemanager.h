#pragma once

#include <map>

class puzzlemanager
{
private:
  std::map<int, std::string> solutions;

public:
  puzzlemanager();
  ~puzzlemanager();
  void printSolutions();
};
