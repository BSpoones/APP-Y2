#pragma once
#include <vector>
#include <string>
#include "SortType.h"
class Item;

class ItemList
{
public:
	std::vector<Item*> items;
	virtual ~ItemList();
	virtual std::string toString();
	void sortItems(SortType sortType = SortType::TYPE_ASCENDING);

	static bool compareItems(const Item* a, const Item* b, SortType sortType);
};