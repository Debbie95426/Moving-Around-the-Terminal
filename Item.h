#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
private:
    char id;
    std::string name;

public:
    explicit Item(char itemId);
    Item(char itemId, const std::string& itemName);
    char getId() const;
    const std::string& getName() const;
    static std::string getNameFromId(char itemId);
};

#endif