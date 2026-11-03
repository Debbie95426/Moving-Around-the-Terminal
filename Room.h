#ifndef ROOM_H
#define ROOM_H

class Player;

class Room {
private:
    int rows, cols;
    char** grid; 
public:
    Room(int r, int c);
    ~Room();

    bool isWall(int x, int y) const;
    void draw(const Player& player) const;
};

#endif