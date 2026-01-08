#include "input_validation.h"
#include <iostream>

double get_double(const std::string& prompt)
{
	std::string input;
	std::cout << prompt;
	std::cin >> input;

	double result = std::stod(input);
	return result;
}

int get_int(const std::string& prompt)
{
	std::string input;
	std::cout << prompt;
	std::cin >> input;

	for (size_t i = 0; i < input.size(); ++i)
	{
		if (i == 0 && input[i] == '-') continue;
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return 0;
	}

	return std::stoi(input);
}

std::string get_string(const std::string& prompt)
{
	std::string input;
	std::cout << prompt;
	std::cin >> input;
	return input;
}
