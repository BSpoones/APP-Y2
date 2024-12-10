#include "Menu.h"
#include "Utils.h"


#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


Menu::Menu(const std::string& path) {
	// Reading file
	std::string line;
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cout << "Failed to open menu csv" << std::endl;
		return;
	}
	// Creating an item per row
	while (getline(file, line)) {
		std::istringstream iss(line);
		std::vector<std::string> row;

		// Splitting by ,
		while (std::getline(iss, line, ',')) {
			row.push_back(line);
		}
		// Adds generated item pointer to item vector
		// via getItem
		items.push_back(Utils::getItem(row));
	}
	// Sorts items after creation to be formatted
	// when viewing the list
	sortItems();
}

std::string Menu::toString(SortType sortType) {
	// Sorts via sort type so the right menu
	// is displayed
	sortItems(sortType);
	std::string output = "";
	
	ItemType lastItemType = ItemType::UNKNOWN;
	for (int i = 1; i <= items.size(); i++) {
		Item* item = items[i-1];
		ItemType itemType = item->getItemType();
		// Will add a title whenever the courses changes, where applicable
		if (lastItemType != itemType && (sortType == SortType::TYPE_ASCENDING || sortType == SortType::TYPE_DESCENDING)){
			output += itemTypeToString(itemType) + "\n";
		}
		output += "(" + std::to_string(i) + ") " + item->toString() + "\n";
		lastItemType = itemType;
	}
	return output;
}

Item* Menu::getItem(int index) {
	// Returns the Item pointer from the menu
	// This updates when a menu is sorted in a
	// different way
	if (index > items.size()) {
		throw std::out_of_range("Out of range");
	}
	return items[index];
}