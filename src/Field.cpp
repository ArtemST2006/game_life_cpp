#include "../include/game.h"

Field::Field(int size, int n, sf::RenderWindow& window) : size(size), n(n), window(window) {
    field.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i].push_back(new Cell(size, i, j, window));
        }
    }
}

Field::~Field() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete field[i][j];
        }
    }
}

void Field::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j]->print();
        }
    }
}
