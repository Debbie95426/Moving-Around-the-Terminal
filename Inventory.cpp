#include "Inventory.h"
Inventory::Inventory() : capacity(2), count(0) {
    items = new Item*[capacity];
    for (int i = 0; i < capacity; ++i) {
        items[i] = nullptr;
    }
}
Inventory::~Inventory() {
    for (int i = 0; i < count; ++i) {
        delete items[i];
    }
    delete[] items;
}

void Inventory::resize() {
    int newCapacity = capacity * 2;
    Item** newItems = new Item*[newCapacity];
    for (int i = 0; i < count; ++i) {
        newItems[i] = items[i];
    }
    for (int i = count; i < newCapacity; ++i) {
        newItems[i] = nullptr;
    }

    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

void Inventory::addItem(Item* item) {
    if (item == nullptr) {
        return;
    }
    if (count == capacity) {
        resize();
    }
    items[count] = item;
    ++count;
}

bool Inventory::removeItemById(char id) {
    for (int i = 0; i < count; ++i) {
        if (items[i] != nullptr && items[i]->getId() == id) {
            delete items[i];
            for (int j = i; j < count - 1; ++j) {
                items[j] = items[j + 1];
            }
            items[count - 1] = nullptr;
            --count;
            return true;
        }
    }
    return false;
}

bool Inventory::hasItem(char id) const {
    for (int i = 0; i < count; ++i) {
        if (items[i] != nullptr && items[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

void Inventory::print(std::ostream& os) const {
    os << "Inventory: ";
    if (count == 0) {
        os << "(empty)\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        if (items[i] != nullptr) {
            os << items[i]->getName() << " (" << items[i]->getId() << ")";
            if (i < count - 1) {
                os << ", ";
            }
        }
    }
    os << '\n';
}