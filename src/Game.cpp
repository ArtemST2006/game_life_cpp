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
            else if (paused && event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    field.recolor(event.mouseButton.x, event.mouseButton.y);
                }
            }
            else if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::P){
                    paused = !paused;
                }
            }

        }

        if (!paused){
            field.next_move();
        }

        window.clear(toS(ColorType::WHITE));
        field.print();
        window.display();
    }
}
