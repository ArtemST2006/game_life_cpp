#include "../../include/union.h"

Game::Game(int size, int n, std::vector<int>& lis, std::vector<int>& lis_d) : size(size), n(n), field(size, n, window, lis, lis_d) {
    int real_size = size * n;
    window.create(sf::VideoMode(real_size, real_size), "SFML Game");
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
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                push_paused();
            }
            else if (paused && event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left)
                    field.recolor(event.mouseButton.x, event.mouseButton.y);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G){
                field.clear();
                if (!paused)
                    push_paused();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A){
                field.init_random();
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

