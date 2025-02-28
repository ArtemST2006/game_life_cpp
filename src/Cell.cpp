#include "../include/game.h"

Cell::Cell(int size, int x, int y, sf::RenderWindow& window) : x(x), y(y), size(size), window(window) {
    pos_x = x * size;
    pos_y = y * size;
    rect.setSize(sf::Vector2f(size, size));
    rect.setPosition(pos_x, pos_y);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(toS(ColorType::GRAY));
    color = ColorType::WHITE;
}

void Cell::print() {
    window.draw(rect);
}

void Cell::recolor() {
    if (color == ColorType::WHITE) {
        color = ColorType::GREEN;
        rect.setFillColor(toS(color));
    }
    else{
        color = ColorType::WHITE;
        rect.setFillColor(toS(color));
    }   
    alife *= -1;
}
