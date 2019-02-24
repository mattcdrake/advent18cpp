#include "day.h"
#include <iostream>
#include <fstream>
#include <string>

day::day() = default;

/*
  Takes a filepath and returns a vector containing each non-blank
  line in the file. Prints an error to console if the file is not found.
*/
std::vector<std::string> day::parse_input_lines(const std::string &filepath) const
{
	auto infile = std::ifstream(filepath);
	if (!infile)
	{
		std::cout << "Error: Missing day input file" << std::endl;
	}
	std::vector<std::string> out_vector;
	std::string file_line;

	while (!infile.eof())
	{
		std::getline(infile, file_line, '\n');
		if (file_line != "\n" || file_line != "\r\n")
		{
			out_vector.push_back(file_line);
		}
	}
	return out_vector;
}
