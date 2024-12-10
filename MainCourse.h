#pragma once

#include <string>
#include "Item.h"

class MainCourse : public Item{
public:
	MainCourse(
		std::string name,
		double price,
		int calories
	);
protected:
	std::string toString();
	ItemType getItemType() const override;
};