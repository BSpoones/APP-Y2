#include "MainCourse.h"
#include <string>

MainCourse::MainCourse(
	std::string name,
	double price,
	int calories
) : Item(name, price, calories) {}

ItemType MainCourse::getItemType() const {
	return ItemType::MAIN;
}

std::string MainCourse::toString() {
	return Item::toString();
}