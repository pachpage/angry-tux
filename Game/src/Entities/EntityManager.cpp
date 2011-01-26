#include "EntityManager.h"

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
    _arrTexture.clear();
    _arrBar.clear();
    _arrBear.clear();
    _arrTux.clear();
}

void EntityManager::init(sf::RenderWindow* app
                        ,b2World* world) {
    _app = app;
    _world = world;
    _layer_count = 0;
}

void EntityManager::loadTexture (int layer_position
                                 ,std::string str_class
                                 ,sf::Vector2i position
                                 ,std::string path_texture
                                 ,sf::Vector2i dimension
                                 ,float angle
                                 ,bool repeat_x
                                 ,bool repeat_y
                                 ,std::string color) {
    if (path_texture.size() == 0) {
        path_texture = "null.png";
    }

    if (str_class == "texture") {
        _arrTexture.insert(std::pair<int, Texture*>(layer_position, new Texture(_app, position, path_texture, dimension, angle, repeat_x, repeat_y, color)));
    } else {
        _arrTexture.insert(std::pair<int, Texture*>(layer_position, new Obstacle(_app, position, path_texture, dimension, angle, repeat_x, repeat_y, color,_world)));
    }

    if (layer_position > _layer_count) {
        _layer_count = layer_position;
    }
 }

void EntityManager::loadBar (sf::Vector2i position
                             ,std::string path_texture
                             ,sf::Vector2i dimension
                             ,float angle
                             ,int type) {
    _arrBar.push_back(new Bar(_app, position, path_texture, dimension, angle, type, _world));
}

void EntityManager::loadBear (sf::Vector2i position
                             ,std::string path_texture
                             ,int size
                             ,int score) {
    _arrBear.push_back(new Bear(_app, position, path_texture, size, score, _world));
 }

void EntityManager::loadTux (sf::Vector2i position
                            ,std::string path_texture
                            ,int type) {
    _arrTux.push_back(new Tux(_app, position, path_texture, type, _world));
}

void EntityManager::render() {
    //We render the background order by position
    for(int i=0; i <= _layer_count; i++) {
        std::multimap<int, Texture*>::iterator itr = _arrTexture.find(i);
        if(itr != _arrTexture.end()) {
            do {
                itr->second->render();
                ++itr;
            } while (itr != _arrTexture.upper_bound(i));
        }
    }

    std::vector<Bar*>::iterator itrB;
    for(itrB = _arrBar.begin(); itrB != _arrBar.end(); itrB++) {
        (*itrB)->render();
    }

    std::vector<Bear*>::iterator itrBe;
    for(itrBe = _arrBear.begin(); itrBe != _arrBear.end(); itrBe++) {
        (*itrBe)->render();
    }

    std::vector<Tux*>::iterator itrT;
    for(itrT = _arrTux.begin(); itrT != _arrTux.end(); itrT++) {
        (*itrT)->render();
    }
}

void EntityManager::stop() {
    _arrTexture.clear();
    _arrBar.clear();
    _arrBear.clear();
    _arrTux.clear();
}
