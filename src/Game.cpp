#include "../include/game.h"

Game::Game(int size, int n) : size(size), n(n), field(size, n, window) {
    window.create(sf::VideoMode(size * n, size * n), "SFML Game");
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(GRAY);
        field.print();
        window.display();
    }
}
