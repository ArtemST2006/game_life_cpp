#include "../../include/union.h"

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

ColorType to_cColr(std::string c){
    if (c == "white") return ColorType::WHITE;
    if (c == "black") return ColorType::BLACK;
    if (c == "gray") return ColorType::GRAY;
    if (c == "green") return ColorType::GREEN;
    if (c == "red") return ColorType::RED;
    return ColorType::GREEN;
}