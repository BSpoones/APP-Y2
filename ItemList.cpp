#include "ItemList.h"
#include "Item.h"
#include "SortType.h"
#include <algorithm>

ItemList::~ItemList() {}

std::string ItemList::toString() { return  ""; }

bool ItemList::compareItems(const Item* a, const Item* b, SortType sortType = SortType::TYPE_ASCENDING) {
	// Algorithm to compare items against
	switch (sortType) {
	case SortType::TYPE_ASCENDING:
		// Showing courses from Appetiser - Beverage
		if (a->getItemType() != b->getItemType()) {
			return a->getItemType() < b->getItemType();
		}
		return a->getName() < b->getName();
	case SortType::TYPE_DESCENDING:
		// Showing courses in reverse order
		if (a->getItemType() != b->getItemType()) {
			return a->getItemType() > b->getItemType();
		}
		return a->getName() < b->getName();
	case SortType::PRICE_ASCENDING:
		// Ignoring courses
		return a->getPrice() < b->getPrice();
	case SortType::PRICE_DESCENDING:
		return a->getPrice() > b->getPrice();
	}
}



void ItemList::sortItems(SortType sortType) {
	// Sorts the object's items based on the sortType
	std::sort(items.begin(), items.end(), [sortType = sortType](const Item* a, const Item* b) {
		return compareItems(a, b, sortType);
		});
}
