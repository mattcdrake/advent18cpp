#include "pch.h"
#include "day.h"
#include <iostream>
#include <fstream>
#include <string>

day::day()
{
}

/*
  Takes a filepath and returns a vector containing each non-blank
  line in the file. Prints an error to console if the file is not found.
*/
std::vector<std::string> day::parseInputLines(std::string filepath)
{
	std::ifstream infile = std::ifstream(filepath);
	if (!infile)
	{
		std::cout << "Error: Missing day input file" << std::endl;
	}
	std::vector<std::string> outvec;
	std::string fileline;

	while (!infile.eof())
	{
		std::getline(infile, fileline, '\n');
		if (fileline != "\n" || fileline != "\r\n")
		{
			outvec.push_back(fileline);
		}
	}
	return outvec;
}
