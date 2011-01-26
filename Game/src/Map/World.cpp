#include "World.h"

World::World(std::string directory, std::string name, std::string file_name) : _directory(directory), _name(name) {
    _image = RessourceManager::Instance()->GetImage(Config::Instance()->image_path + "worlds/" + file_name);
    _sprite.SetImage(*_image);
}

std::string& World::getDirectory() {
    return _directory;
}

std::string& World::getName() {
    return _name;
}

sf::Sprite& World::getSprite() {
    return _sprite;
}
