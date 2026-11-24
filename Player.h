#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Inventory.h"

class Room;

class Player {
private:
    int x, y;
    Inventory inventory;
public:
    Player(int startX, int startY);

    int getX() const;
    int getY() const;

    void move(char key, Room& room);
    void printInventory(std::ostream& os = std::cout) const;
};

#endif