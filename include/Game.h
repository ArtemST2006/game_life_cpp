#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

enum class ColorType {
    WHITE,
    BLACK,
    GRAY,
    GREEN,
    RED
};

sf::Color toS(ColorType);

class Cell {
private:
    int size, x, y;
    int pos_x, pos_y;
    sf::RenderWindow& window;
    sf::RectangleShape rect;
public:
    ColorType color;
    int alife = -1;
    Cell(int size, int x, int y, sf::RenderWindow& window);
    void print();
    void recolor();
};

class Field {
private:
    int size, n;
    std::vector<std::vector<std::pair<Cell*, int>>> field;
protected:
    sf::RenderWindow& window;
public:
    Field(int size, int n, sf::RenderWindow& window);
    ~Field();
    void print();
    void recolor(int x, int y);
    void next_move();
    void in_rm_neighbors(int, int, int);
};

class Game {
private:
    sf::RenderWindow window;
    Field field;
    int size, n;
    bool paused = true;
public:
    Game(int size, int n);
    void run();
};
