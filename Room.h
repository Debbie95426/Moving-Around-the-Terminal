#ifndef ROOM_H
#define ROOM_H

class Player;
class Item;

class Room {
private:
    int rows, cols;
    char** grid; 
public:
    Room(int r, int c);
    ~Room();

    bool isWall(int x, int y) const;
    void draw(const Player& player) const;
    void placeItem(Item* item);
    char takeItem(int x, int y);
};

#endif