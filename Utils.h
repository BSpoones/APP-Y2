#pragma once
#include "item.h"
#include <string>
#include <vector>

namespace Utils {
	Item* getItem(std::vector<std::string> row);
	bool parseBool(std::string item);
	std::string formatDouble(double val, int precision);

}