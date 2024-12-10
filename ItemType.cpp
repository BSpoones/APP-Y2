#include "ItemType.h"


std::string ItemType::itemTypeToString(ItemType type) {
    switch (type) {
    case ItemType::APPETISER: return "Appetiser";
    case ItemType::MAIN: return "Main Course";
    case ItemType::BEVERAGE: return "Beverage";
    default: return "Unknown";
    }
}