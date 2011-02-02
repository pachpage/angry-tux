#include "Map.h"
#include <tinyxml.h>
#include <tinyxml.cpp>
#include <tinyxmlerror.cpp>
#include <tinyxmlparser.cpp>
#include <tinystr.cpp>
#include <tinystr.h>

Map::Map(std::string& file, int id, std::string world) : _world(world), _file(file)
{
    _id = id;
    TiXmlDocument doc( file.c_str() );
    if (!doc.LoadFile()) {
        Logger::Instance()->log("Unable to load the map : " + file + ":" + doc.ErrorDesc());
    } else {
        TiXmlHandle hdl(&doc);
        try {
            TiXmlElement *map;
            map      = hdl.FirstChildElement("map").Element();
            _name    = map->Attribute("name");
            _author  = map->Attribute("author");
            _date    = map->Attribute("date");
            _version = map->Attribute("version");
            map->QueryIntAttribute("width", &_mapSize.x);
            map->QueryIntAttribute("height", &_mapSize.y);
        } catch(...) {
            Logger::Instance()->log("The map structure is unknown.");
            Logger::Instance()->log(doc.ErrorDesc());
        }
    }
}

Map::~Map() {
}

void Map::load() {
    TiXmlDocument doc( _file.c_str() );
    if (!doc.LoadFile()) {
        Logger::Instance()->log("Unable to load the map : " + _file + ":" + doc.ErrorDesc());
    } else {
        TiXmlHandle hdl(&doc);
        try {
            TiXmlElement *map,*layers,*layer,*texture,*bar,*bear,*tux;
            map = hdl.FirstChildElement("map").Element();

            //Load layers
            layers = map->FirstChildElement("layers");
            while (layers) {
                layer = layers->FirstChildElement("layer");
                int layer_position = 0;
                while (layer) {
                    texture = layer->FirstChildElement("texture");
                    while (texture) {
                        sf::Vector2i position;
                        sf::Vector2i dimension;
                        bool repeat_x, repeat_y;
                        float angle;
                        std::string str_class,path_texture, str_rx, str_ry, color;

                        if (texture->QueryIntAttribute("x", &position.x) != TIXML_SUCCESS) {
                            Logger::Instance()->log("Attribute x doesn't exist in layer.");
                        }
                        if (texture->QueryIntAttribute("y", &position.y) != TIXML_SUCCESS) {
                            Logger::Instance()->log("Attribute y doesn't exist in layer.");
                        }
                        if (texture->QueryIntAttribute("width", &dimension.x) != TIXML_SUCCESS) {
                            Logger::Instance()->log("Attribute width doesn't exist in layer.");
                        }
                        if (texture->QueryIntAttribute("height", &dimension.y) != TIXML_SUCCESS) {
                            Logger::Instance()->log("Attribute height doesn't exist in layer.");
                        }
                        if (texture->QueryFloatAttribute("angle", &angle) != TIXML_SUCCESS) {
                            Logger::Instance()->log("Attribute angle doesn't exist in texture tag.");
                        }
                        str_class    = texture->Attribute("class");
                        path_texture = texture->Attribute("texture");
                        color        = texture->Attribute("color");
                        str_rx       = texture->Attribute("repeat_x");
                        repeat_x     = (str_rx == "true");
                        str_ry       = texture->Attribute("repeat_y");
                        repeat_y     = (str_ry == "true");
                        EntityManager::Instance()->loadTexture(layer_position, str_class, position, path_texture, dimension, angle, repeat_x, repeat_y, color);

                        texture = texture->NextSiblingElement();
                        layer_position++;
                    }
                    layer = layer->NextSiblingElement();
                }
                layers = layers->NextSiblingElement();
            }

            //Load bars
            bar = hdl.FirstChildElement("map").FirstChild("bars").FirstChildElement().Element();
            while (bar) {
                sf::Vector2i position;
                sf::Vector2i dimension;
                std::string path_texture;
                int type;
                float angle;

                if (bar->QueryIntAttribute("x", &position.x) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute x doesn't exist in bar tag.");
                }
                if (bar->QueryIntAttribute("y", &position.y) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute y doesn't exist in bar tag.");
                }
                if (bar->QueryIntAttribute("width", &dimension.x) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute width doesn't exist in bar tag.");
                }
                if (bar->QueryIntAttribute("height", &dimension.y) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute height doesn't exist in bar tag.");
                }
                if (bar->QueryIntAttribute("type", &type) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute type doesn't exist in bar tag.");
                }
                if (bar->QueryFloatAttribute("angle", &angle) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute angle doesn't exist in bar tag.");
                }
                path_texture = bar->Attribute("texture");
                EntityManager::Instance()->loadBar(position, path_texture, dimension, angle, type);

                bar = bar->NextSiblingElement();
            }

            //Load bears
            bear = hdl.FirstChildElement("map").FirstChild("bears").FirstChildElement().Element();
            while (bear) {
                sf::Vector2i position;
                int size, score;
                std::string path_texture;

                if (bear->QueryIntAttribute("x", &position.x) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute x doesn't exist in bear tag.");
                }
                if (bear->QueryIntAttribute("y", &position.y) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute y doesn't exist in bear tag.");
                }
                if (bear->QueryIntAttribute("size", &size) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute size doesn't exist in bear tag.");
                }
                if (bear->QueryIntAttribute("score", &score) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute score doesn't exist in bear tag.");
                }
                path_texture = bear->Attribute("texture");
                EntityManager::Instance()->loadBear(position, path_texture, size, score);

                bear = bear->NextSiblingElement();
            }

            //Load tuxs
            tux = hdl.FirstChildElement("map").FirstChild("tuxs").FirstChildElement().Element();
            while (tux) {
                sf::Vector2i position;
                std::string path_texture;
                int type;

                if (tux->QueryIntAttribute("x", &position.x) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute x doesn't exist in tux tag.");
                }
                if (tux->QueryIntAttribute("y", &position.y) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute y doesn't exist in tux tag.");
                }
                if (tux->QueryIntAttribute("type", &type) != TIXML_SUCCESS) {
                    Logger::Instance()->log("Attribute type doesn't exist in tux tag.");
                }
                path_texture = tux->Attribute("texture");
                EntityManager::Instance()->loadTux(position, path_texture, type);

                tux = tux->NextSiblingElement();
            }
            Logger::Instance()->log("Map " + _file + " loaded");
        } catch(...) {
            Logger::Instance()->log("The map structure is unknown.");
            Logger::Instance()->log(doc.ErrorDesc());
        }
    }
}

int Map::getId() const {
    return _id;
}

std::string& Map::getWorld() {
    return _world;
}

std::string& Map::getName() {
    return _name;
}

std::string& Map::getAuthor() {
    return _author;
}

std::string& Map::getDate() {
    return _date;
}

std::string& Map::getVersion() {
    return _version;
}

sf::Vector2i& Map::getMapSize() {
    return _mapSize;
}
