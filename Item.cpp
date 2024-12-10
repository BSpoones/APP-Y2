
#include <string>
#include "Item.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

Item::Item(
	std::string name,
	double price,
	int calories
) : name(name), price(price), calories(calories) {}

std::string Item::getName() const { return name; }
int Item::getCalories() { return calories; }
double Item::getPrice() const { return price; }

// Returns value shown in the menu, showing
// all arguments
std::string Item::toString() {
	return 
		getName() + ": " +
		// Using \x9c as val for £
		"\x9C" + Utils::formatDouble(price,2) + ", " +
		std::to_string(getCalories()) + "cal ";
}

// Returns value shown in a reciept, only showing
// name and price
std::string Item::toReceipt() {
	return name + " - " + "\x9C" + Utils::formatDouble(price,2);
}