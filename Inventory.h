#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "Item.h"

class Inventory {
private:
    Item** items;
    int capacity;
    int count;

    void resize();

public:
    Inventory();
    ~Inventory();

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    void addItem(Item* item);
    bool removeItemById(char id);
    bool hasItem(char id) const;
    void print(std::ostream& os = std::cout) const;
};

#endif