#include "../include/game.h"
#include <vector>

Field::Field(int size, int n, sf::RenderWindow& window) : size(size), n(n), window(window) {
    field.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i].push_back({new Cell(size, i, j, window), 0});
        }
    }
}

Field::~Field() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete field[i][j].first;
        }
    }
}

void Field::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j].first->print();
        }
    }
}

void Field::in_rm_neighbors(int i, int j, int mode=0) {
    int r_x = (i + 1) % n, l_x = (i - 1 + n) % n;
    int u_y = (j + 1) % n, d_y = (j - 1 + n) % n;
    field[l_x][j].second += mode;
    field[r_x][j].second += mode;
    field[i][u_y].second += mode;
    field[i][d_y].second += mode;

    field[l_x][u_y].second += mode;
    field[l_x][d_y].second += mode;
    field[r_x][u_y].second += mode;
    field[r_x][d_y].second += mode;
}


void Field::recolor(int x, int y) {
    int i = x/size, j = y/size;
    field[i][j].first->recolor();
    in_rm_neighbors(i, j, field[i][j].first->alife);
}


void Field::next_move() {
    std::vector<std::pair<int, int>> to_flip;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j].first->alife == -1 && field[i][j].second == 3) {
                to_flip.push_back({i, j});
            } 
            else if (field[i][j].first->alife == 1 && !(field[i][j].second == 3 || field[i][j].second == 2)) {
                to_flip.push_back({i, j});
            }
        }
    }

    for (auto [i, j] : to_flip) {
        recolor(i * size, j * size);
    }
}
