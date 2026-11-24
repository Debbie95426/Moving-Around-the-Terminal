#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Item.h"
int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Room room(rows, cols);
    Item* keyItem = new Item('k');
    Item* coinItem = new Item('c');
    room.placeItem(keyItem);
    room.placeItem(coinItem);
    delete keyItem;
    delete coinItem;

    Player player(1, 1);

    char input;
    while (true) {
        room.draw(player);
        player.printInventory();

        std::cout << "Move (w: up, s: down, a: left, d: right, q: quit): ";
        std::cin >> input;

        if (input == 'q') {
            std::cout << "Quitting game.\n";
            break;
        }

        player.move(input, room);
    }

    return 0;
}