#include "Room.h"
#include "Player.h"
#include <iostream>

Room::Room(int r, int c) : rows(r), cols(c) {
    grid = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                grid[i][j] = '#'; 
            } else {
                grid[i][j] = ' '; 
            }
        }
    }
}

Room::~Room() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

bool Room::isWall(int x, int y) const {
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        return true;
    }
    return grid[x][y] == '#';
}

void Room::draw(const Player& player) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == player.getX() && j == player.getY()) {
                std::cout << '@';
            } else {
                std::cout << grid[i][j];
            }
        }
        std::cout << '\n';
    }
}