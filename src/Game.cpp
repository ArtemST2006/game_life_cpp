#include "../include/game.h"

Game::Game(int size, int n) : size(size), n(n), field(size, n, window) {
    window.create(sf::VideoMode(size * n, size * n), "SFML Game");
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            std::lock_guard<std::mutex> lock(eventMutex);
            events.push(event);
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

bool Game::is_open() {
    return window.isOpen();
}

sf::RenderWindow& Game::get_window() {
    return window;
}