#include "../include/game.h"

sf::Color toS(ColorType color) {
    switch (color) {
        case ColorType::WHITE: return sf::Color::White;
        case ColorType::BLACK: return sf::Color::Black;
        case ColorType::GRAY: return sf::Color(153, 153, 153);
        case ColorType::GREEN: return sf::Color::Green;
        case ColorType::RED: return sf::Color::Red;
    }
    return sf::Color::White; 
}


void sleep(int m){
    std::this_thread::sleep_for(std::chrono::milliseconds(m));
}

void processing_events(States& states, Game& game){
    while (true){
        if (!game.is_open()) break;
        
        if(!game.events.empty()){
            std::lock_guard<std::mutex> lock(eventMutex);
            sf::Event event = game.events.front();
            game.events.pop();

            if (event.type == sf::Event::Closed){
                game.get_window().close();
                states.get_window().close();
                break;
            }
            else if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::A)
                    game.paused = !game.paused;
            }
            else if (game.paused && event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left)
                    game.field.recolor(event.mouseButton.x, event.mouseButton.y);
            }
        }

        if (!states.events.empty()){
            std::lock_guard<std::mutex> lock(eventMutex);
            sf::Event event = states.events.front();
            states.events.pop();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                time_sleep = std::min(time_sleep + 10, 400);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                time_sleep = std::max(time_sleep - 10, 10);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
