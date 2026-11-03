#ifndef PLAYER_H
#define PLAYER_H

class Room;

class Player {
private:
    int x, y; 
public:
    Player(int startX, int startY);

    int getX() const;
    int getY() const;

    void move(char key, const Room& room);
};

#endif