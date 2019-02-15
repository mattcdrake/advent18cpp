#include "pch.h"
#include "day3.h"
#include "helpers.h"
#include <iostream>
#include <vector>

day3::day3()
{
  this->inputlines = parseInputLines("input_data\\day3.txt");
}

std::string day3::solve1()
{
  for (std::vector<std::string>::iterator it = this->inputlines.begin();
       it != this->inputlines.end();
       it++)
  {
    std::string line = *it;
    FabricSpec spec = buildFabricSpec(line);
    /* Used to test buildFabricSpec():
    std::cout << "Original line: " << line << std::endl;
    std::cout << "Id: " << spec.id << std::endl;
    std::cout << "Left Margin: " << spec.leftMargin << std::endl;
    std::cout << "Top Margin: " << spec.topMargin << std::endl;
    std::cout << "Width: " << spec.width << std::endl;
    std::cout << "Height: " << spec.height << std::endl;
    std::cout << "----------------" << std::endl;
    */
  }
  return "Placeholder day 3 puzzle 1";
}

std::string day3::solve2()
{
  return "Placeholder day 3 puzzle 2";
}

day3::FabricSpec day3::buildFabricSpec(std::string input)
{
  FabricSpec output = {0, 0, 0, 0, 0};
  // Tokens: 0 - id, 1 - useless, 2 - left/top margins, 3 - width/height
  std::vector<std::string> tokens = splitString(input, ' ');

  // Omit the '#' char
  output.id = std::stoi(tokens[0].substr(1));

  int commaPos = tokens[2].find(',');
  output.leftMargin = std::stoi(tokens[2].substr(0, commaPos));
  output.topMargin = std::stoi(tokens[2].substr(commaPos + 1));

  int xpos = tokens[3].find('x');
  output.width = std::stoi(tokens[3].substr(0, xpos));
  output.height = std::stoi(tokens[3].substr(xpos + 1));

  return output;
}

struct FabricSpec
{
  int id;
  int leftMargin;
  int topMargin;
  int width;
  int height;
};

