#pragma once
#include<string>
#include "Item.h"

class Beverage : public Item {
public:
	Beverage(
		const std::string& name,
		double price,
		int calories,
		int volume,
		double abv
	);
	bool isAlcoholic();

private:
	int volume;
	double abv;

protected:
	ItemType getItemType() const override;
	std::string toString();
};