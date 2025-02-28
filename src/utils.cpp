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