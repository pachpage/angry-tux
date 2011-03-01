#include "Conversion.h"

Conversion::Conversion() {
}

float Conversion::to_degres(float angle) {
    return angle * 180 / PI;
}

float Conversion::to_radian(float angle) {
    return angle * PI / 180;
}

sf::Vector2i Conversion::to_sfmlcoord(sf::Vector2i position) {
    return sf::Vector2i(position.x, Config::Instance()->height - position.y);
}

sf::Vector2f Conversion::to_sfmlcoord(sf::Vector2f position) {
    return sf::Vector2f(position.x, Config::Instance()->height - position.y);
}

sf::Vector2i Conversion::to_sfmlcoord(int x, int y) {
    return sf::Vector2i(x, Config::Instance()->height - y);
}
