#include "../include/game.h"


States::States(Game& game) : game(game) {
    window.create(sf::VideoMode(400, 400), "Settings");
}

void States::run(){

    sf::Font font;
    font.loadFromFile("../fonts/arial/arial.ttf");

    sf::Text size("Size: " + std::to_string(game.size * game.n) + "x" + std::to_string(game.size * game.n), font, 30);
    size.setFillColor(toS(ColorType::BLACK));
    size.setPosition(15, 50);

    sf::Text speed("Speed: ", font, 30);
    speed.setPosition(15, 15);
    speed.setFillColor(toS(ColorType::BLACK));
    while (window.isOpen() && game.is_open()){

        sf::Event event;
        while (window.pollEvent(event)){
            std::lock_guard<std::mutex> lock(eventMutex);
            events.push(event);
        }
        sf::sleep(sf::milliseconds(10));

        window.clear(toS(ColorType::WHITE));
    
        speed.setString("Speed: " + std::to_string(500 - time_sleep));

        window.draw(speed);
        window.draw(size);
        window.display();
    }

}

sf::RenderWindow& States::get_window() {
    return window;
}