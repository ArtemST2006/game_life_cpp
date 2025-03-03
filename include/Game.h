#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <mutex>
#include <iostream>
#include <string>

enum class ColorType {
    WHITE,
    BLACK,
    GRAY,
    GREEN,
    RED
};

class Cell {
private:
    int size, x, y;
    int pos_x, pos_y;
    sf::RenderWindow& window;
    sf::RectangleShape rect;
    ColorType color;
public:
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
    void init_random();
};



class Game {
private:
    sf::RenderWindow window;
    Field field;
    bool paused = true;
    int size, n;
    bool running = true;
public:
    Game(int size, int n);
    void run();
    inline bool is_open() {return window.isOpen();};
    inline sf::RenderWindow& get_window() {return window;}; 
    // void init_settings_window(sf::RenderWindow& window);
    inline void push_paused() {paused = !paused;}
    inline int get_n(){return n;}
    inline int get_size(){return size;}
    inline bool is_running() {return running;}
    inline void init_random(){ field.init_random(); }
};

class States {
    private:
        Game& game;
        sf::RenderWindow window;
    public:
        States(Game&);
        void run();
        inline sf::RenderWindow& get_window() {return window;};
    };

extern int time_sleep;
extern ColorType color_cell;
extern int amount;

void sleep(int);
sf::Color toS(ColorType);
ColorType to_cColr(std::string);

