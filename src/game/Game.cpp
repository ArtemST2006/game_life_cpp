#include "../../include/game.h"

Game::Game(int size, int n) : size(size), n(n), field(size, n, window) {
    window.create(sf::VideoMode(size * n, size * n), "SFML Game");
    window.setActive(false);
}

void Game::run() {
    window.setActive(true);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                running = false;
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::A)
                    push_paused();
            }
            else if (paused && event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left)
                    field.recolor(event.mouseButton.x, event.mouseButton.y);
            }
        }

        if (!paused){
            sleep(time_sleep);
            field.next_move();
        }

        window.clear(toS(ColorType::WHITE));
        field.print();
        window.display();
    }
}