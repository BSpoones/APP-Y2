#include "Beverage.h"
#include "Utils.h"
#include <iostream>


Beverage::Beverage(
	const std::string& name,
	double price,
	int calories,
	int volume,
	double abv
) : Item(name, price, calories),  volume(volume), abv(abv) {};

ItemType Beverage::getItemType() const {
	return ItemType::BEVERAGE;
}

bool Beverage::isAlcoholic() {
return abv != 0;
}

std::string Beverage::toString() {

	std::string output = "";
	output += Item::toString();
	// Adding volume
	output += "(" + std::to_string(volume) + "ml";

	// Adding abv where applicable
	if (isAlcoholic()) {
		output += " " + Utils::formatDouble(abv,1) + "\x25 abv";
	}
	output += +") ";

	return output;
}
