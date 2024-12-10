
#pragma once
#include <string>
#include "ItemType.h"

class Item
{
public:
	Item(
		std::string name,
		double price,
		int calories
		);
	std::string getName() const;
	double getPrice() const;
	int getCalories();

	virtual std::string toString();
	virtual std::string toReceipt();
	virtual ItemType getItemType() const = 0;
private:
	std::string name;
	double price;
	int calories;
};