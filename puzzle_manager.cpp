#include "dayWrapper.h"
#include "puzzle_manager.h"
#include <iostream>
#include <string>

puzzle_manager::puzzle_manager()
{
    day1 *day_1 = new day1();
    solutions.insert(std::pair<int, std::string>(1, day_1->solve1()));
    solutions.insert(std::pair<int, std::string>(2, day_1->solve2()));
    delete day_1;

    day2 *day_2 = new day2();
    solutions.insert(std::pair<int, std::string>(3, day_2->solve1()));
    solutions.insert(std::pair<int, std::string>(4, day_2->solve2()));
    delete day_2;

    day3 *day_3 = new day3();
    solutions.insert(std::pair<int, std::string>(5, day_3->solve1()));
    solutions.insert(std::pair<int, std::string>(6, day_3->solve2()));
    delete day_3;
}

void puzzle_manager::printSolutions()
{
    std::cout << "Solutions to Advent of Code 2018 Puzzles" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    int puzzleCount = 1;

    for (std::map<int, std::string>::iterator it = solutions.begin(); it != solutions.end(); it++)
    {
        std::cout << "Solution #" << puzzleCount << ": " << it->second << std::endl;
        puzzleCount++;
    }
}
