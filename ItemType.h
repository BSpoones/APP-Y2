#pragma once
#include <string>

enum class ItemType {
	APPETISER,
	MAIN,
	BEVERAGE,
    UNKNOWN // Used for comparasons 
};

inline std::string itemTypeToString(ItemType type) {
    // Returns the formatted menu course name
    switch (type) {
    case ItemType::APPETISER: return "--==[ Appetisers ]==--";
    case ItemType::MAIN: return "--==[ Main Courses ]==--";
    case ItemType::BEVERAGE: return "--==[ Beverages ]==--";
    case ItemType::UNKNOWN: return "--==[ Unknown ]==--";
    }
}