#pragma once
#include "ItemList.h"

class Menu : ItemList
{
public:
	Menu(const std::string& path);
	virtual std::string toString(SortType sortType);
	Item* getItem(int index);
};