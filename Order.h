#pragma once
#include <string>
#include "ItemList.h"


class Order : public ItemList {
public:
	double total;

	Order();
	std::string toString();

	std::vector<double> calculateTotal();
	void printReceipt();

	void addItem(std::vector<Item*> items);
	void addItem(Item* item);

	void removeItem(std::vector<int> indexes);
	void removeItem(int index);

};