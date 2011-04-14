#include "Canon.h"

Canon::Canon(sf::RenderWindow* app
            ,sf::Vector2i& position
            ,std::string path) : Entity(app, position, path, 0) {

}

void Canon::setAngle(float angle) {
    _sprite.SetRotation(angle);
}

void Canon::render() {
   // _app->Draw(_sprite);
}
