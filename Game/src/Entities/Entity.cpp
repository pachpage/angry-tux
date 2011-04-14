#include "Entity.h"

Entity::Entity(sf::RenderWindow* app, sf::Vector2i& position, std::string& path, float angle)
        : _app(app), _position(position) {
    _image = RessourceManager::Instance()->GetImage(Config::Instance()->image_path + path);
    _sprite.SetImage(*_image);
    _sprite.SetRotation(angle);
}

Entity::~Entity() {
}
