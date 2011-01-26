#include "MapManager.h"
#include <sstream>
#include <fstream>

MapManager::MapManager() {
}

MapManager::~MapManager() {
    _arrWorld.clear();
    _arrMap.clear();
}

void MapManager::init() {
    _next_id = 1;
    _currentMap = NULL;
    loadWorldList(Config::Instance()->maps_path + "/worlds.lst");
    loadMapList(&Config::Instance()->maps_path);
}

void MapManager::stop() {
    if (_currentMap != NULL) {
        delete _currentMap;
    }
}

Map* MapManager::setMap(const std::string &world, int map_id) {
    std::multimap<std::string, Map*>::iterator i;
    for (i = _arrMap.lower_bound(world); i != _arrMap.upper_bound(world); i++) {
	       if (i->second->getId() == map_id) {
                _currentMap = i->second;
                return _currentMap;
	       }
    }
    return NULL;
}

Map* MapManager::setNextMap() {
    if (_currentMap != NULL) {
        std::multimap<std::string, Map*>::iterator i;
        bool found = false;
        for (i = _arrMap.lower_bound(_currentMap->getWorld()); i != _arrMap.upper_bound(_currentMap->getWorld()); i++) {
            if (found) {
                _currentMap = i->second;
                return _currentMap;
            }
            if (i->second->getId() == _currentMap->getId()) {
                found = true;
            }
        }
    }
    return NULL;
}

void MapManager::loadMapList(const std::string *path) {
    DIR * worlddir = opendir(path->c_str());
    if (worlddir != NULL) {
        struct dirent *worldent, *mapent;

        while ((worldent = readdir(worlddir)) != NULL) {
            if (worldent->d_type==DT_DIR) {
                std::string temp_path = *path;
                temp_path += "/";
                temp_path += worldent->d_name;

                DIR *mapdir = opendir(temp_path.c_str());
                if (mapdir != NULL) {
                    while ((mapent = readdir(mapdir)) != NULL) {
                        std::string file = mapent->d_name;
                        int pos = file.length();
                        while(pos > 0) {
                            if(file[pos] == '.') {
                                break;
                            }
                            pos--;
                        }
                        if (file.substr(pos + 1, file.length() - pos - 1) == "xml") {
                            std::string path = temp_path + "/" + file;
                            _arrMap.insert(std::pair<std::string, Map*>(worldent->d_name, new Map(path, _next_id, worldent->d_name)));
                            _next_id++;
                        }
                    }
                    closedir(mapdir);
                } else {
                    Logger::Instance()->log("Unable to open " + temp_path);
                }
            }
        }
        closedir(worlddir);
        Logger::Instance()->log(*path + " listed");
    } else {
        Logger::Instance()->log("Unable to open " + *path);
    }
}

void MapManager::loadWorldList(const std::string path) {
    std::fstream map_list(path.c_str(), std::ios::in);
    std::string line;

    if (map_list.is_open()) {
        while(getline(map_list, line)) {
            int i = line.find('|');
            std::string directory, name, file_name;
            directory = line.substr(0, i);
            name = line.substr(directory.length() + 1, line.find('|', i+1) - directory.length() - 1);
            file_name = line.substr(line.find('|', i+1) + 1, line.length());
            _arrWorld.push_back(new World(directory, name, file_name));

        }
        map_list.close();
        Logger::Instance()->log(path + " parsed");
    } else {
        Logger::Instance()->log("Unable to open " + path);
    }
}

std::vector<Map*> MapManager::getWorldMaps(const std::string& world) {
    std::vector<Map*> mapList;
    std::multimap<std::string, Map*>::iterator i;
    for (i = _arrMap.lower_bound(world); i != _arrMap.upper_bound(world); i++) {
	       mapList.push_back(i->second);
    }
    return mapList;
}

std::vector<World*>& MapManager::getWorlds() {
    return _arrWorld;
}
