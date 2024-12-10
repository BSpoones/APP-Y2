#include "Utils.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include <iostream>
#include <sstream>
#include <iomanip>

/*
Creating an Item child class based on the csv
type.

Returns an item pointer for the created item
*/
Item* Utils::getItem(std::vector<std::string> row) {
	// Error handling
	if (row.size() < 4) {
		std::cout << "Invalid row from CSV" << std::endl;
		return 0;
	}
	std::string itemType = row[0];
	std::string name = row[1];
	double price = std::stod(row[2]);
	int calories = std::stoi(row[3]);
	try {
		// Returning item object based on itemType
		if (itemType == "a") {
			return new Appetiser(
				name,
				price,
				calories,
				parseBool(row[4]),
				parseBool(row[5])
			);
		}
		else if (itemType == "m") {
			return new MainCourse(
				name,
				price,
				calories
			);
		}
		else if (itemType == "b") {
			return new Beverage(
				name,
				price,
				calories,
				std::stod(row[6]),
				std::stod(row[7])
			);
		}
		else {
			std::cerr << "Invalid item type: " << itemType << std::endl;
			return nullptr;
		}
	}
	catch (const std::out_of_range&) {
		std::cerr << "Invalid csv row" << std::endl;
		return 0;
	}
}

/*
Parses a bool from csv into a boolean
*/
bool Utils::parseBool(std::string item) {
	if (item == "y" || item == "Y") return true;
	else if (item == "n" || item == "N") return false;
	else {
		std::cerr << "Invalid bool: " << item << std::endl;
		return 0;
	}
}

/*
Formats a double to be 2dp
*/
std::string Utils::formatDouble(double val, int precision) {
	std::ostringstream ossVal;
	ossVal << std::fixed << std::setprecision(precision) << val;

	return ossVal.str();
}

