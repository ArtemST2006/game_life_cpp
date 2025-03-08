#include "../../include/union.h"


States::States(Game& game) : game(game) {
    window.create(sf::VideoMode(400, 400), "Settings");
    window.setActive(false);
}

void States::run(){
    window.setActive(true);

    sf::Font font;
    font.loadFromFile("../fonts/arial/arial.ttf");

    sf::Text size("Size: " + std::to_string(game.get_size() * game.get_n()) + "x" + std::to_string(game.get_size() * game.get_n()), font, 30);
    size.setFillColor(toS(ColorType::BLACK));
    size.setPosition(15, 50);

    sf::Text speed("Speed: ", font, 30);
    speed.setPosition(15, 15);
    speed.setFillColor(toS(ColorType::BLACK));

    sf::Text am("Amount: ", font, 30);
    am.setPosition(15, 85);
    am.setFillColor(toS(ColorType::BLACK));
    while (window.isOpen() && game.is_running()){

        sf::Event event;
        while (window.pollEvent(event)){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                time_sleep = std::min(time_sleep + 10, 400);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                time_sleep = std::max(time_sleep - 10, 10);
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                game.push_paused();
            }
        }
        
        sf::sleep(sf::milliseconds(10));

        window.clear(toS(ColorType::WHITE));
    
        speed.setString("Speed: " + std::to_string(500 - time_sleep));
        am.setString("Amount: " + std::to_string(amount));

        window.draw(speed);
        window.draw(size);
        window.draw(am);
        window.display();
    }
    window.close();
}
