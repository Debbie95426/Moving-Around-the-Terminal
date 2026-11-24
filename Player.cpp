#include "Player.h"
#include "Room.h" 
#include "Item.h"
Player::Player(int startX, int startY) : x(startX), y(startY) {}

int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::move(char key, Room& room) {
    int newX = x;
    int newY = y;
    if (key == 'w') newX--;
    else if (key == 's') newX++;
    else if (key == 'a') newY--;
    else if (key == 'd') newY++;

    if (!room.isWall(newX, newY)) {
        x = newX;
        y = newY;
        char pickedId = room.takeItem(x, y);
        if (pickedId != 0) {
            inventory.addItem(new Item(pickedId));
        }
    }
}
void Player::printInventory(std::ostream& os) const {
    inventory.print(os);
}