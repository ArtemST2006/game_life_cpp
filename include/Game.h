#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)

class Cell {
private:
    int size, x, y;
    int pos_x, pos_y;
    sf::RenderWindow& window;
    sf::RectangleShape rect;
public:
    Cell(int size, int x, int y, sf::RenderWindow& window);
    void print();
};

class Field {
private:
    int size, n;
    std::vector<std::vector<Cell*>> field;
protected:
    sf::RenderWindow& window;
public:
    Field(int size, int n, sf::RenderWindow& window);
    ~Field();
    void print();
};

class Game {
private:
    sf::RenderWindow window;
    Field field;
    int size, n;
public:
    Game(int size, int n);
    void run();
};
