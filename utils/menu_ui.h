#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>

// Templates are designed in the header files
template<typename Enum>
using MenuItem = std::pair<Enum, std::string>;

template<typename Enum>
void showMenu(const std::vector<MenuItem<Enum>>& menu)
{
	for (const auto& [option, label] : menu)
	{
		std::cout << static_cast<int>(option) << ". " << label << '\n';
	}
}