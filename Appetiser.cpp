#include "Appetiser.h"
#include <iostream>


Appetiser::Appetiser(
	const std::string& name,
	double price,
	int calories,
	bool shareable,
	bool twoForOne
): Item(name,price, calories),shareable(shareable),twoForOne(twoForOne) {};


// Default destructor
Appetiser::~Appetiser() = default;

ItemType Appetiser::getItemType() const {
	return ItemType::APPETISER;
}

std::string Appetiser::toString() {
	std::string output = "";
	output += Item::toString();
	/*
	Adding sharable and 2-4-1 where applicable
	*/
	if (isShareable()) {
		output += "(shareable) ";
	}
	if (isTwoForOne()) {
		output += "(2-4-1) ";
	}
	return output;
}

bool Appetiser::isShareable() const { return shareable; }
bool Appetiser::isTwoForOne() { return twoForOne; }

// Override func to add (2-4-1) suffix to
// applicable items
std::string Appetiser::toReceipt() {
	std::string output = Item::toReceipt();
	if (isShareable()) {
		output += " (2-4-1)";
	}
	return output;
}
