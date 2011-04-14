#include "Conversion.h"

Conversion::Conversion() {
}

float Conversion::to_degres(float angle) {
    return (angle * (180 / PI));
}

float Conversion::to_radian(float angle) {
    return angle * PI / 180;
}

sf::Vector2i Conversion::to_sfmlcoord(sf::Vector2i position) {
    return sf::Vector2i(position.x, 800 - position.y);
}

sf::Vector2f Conversion::to_sfmlcoord(sf::Vector2f position) {
    return sf::Vector2f(position.x, 800 - position.y);
}

sf::Vector2i Conversion::to_sfmlcoord(int x, int y) {
    return sf::Vector2i(x, 800 - y);
}

sf::Vector2i Conversion::to_box2d(int x, int y) {
    return sf::Vector2i(x, y);
}
