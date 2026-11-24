#include "Item.h"

Item::Item(char itemId) : id(itemId), name(getNameFromId(itemId)) {}
Item::Item(char itemId, const std::string& itemName) : id(itemId), name(itemName) {}
char Item::getId() const {
    return id;
}

const std::string& Item::getName() const {
    return name;
}

std::string Item::getNameFromId(char itemId) {
    switch (itemId) {
        case 'k':
            return "key";
        case 'c':
            return "coin";
        default: {
            std::string fallback(1, itemId);
            return fallback;
        }
    }
}