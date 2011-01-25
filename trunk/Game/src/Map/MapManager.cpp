#include "MapManager.h"
#include <sstream>

MapManager::MapManager() {
}

MapManager::~MapManager() {
}

void MapManager::init() {
    _next_id = 1;
    _currentMap = NULL;
    loadMapList(&Config::Instance()->maps_path);
}

void MapManager::stop() {
    if (_currentMap != NULL) {
        delete _currentMap;
    }
}

Map* MapManager::setMap(const int world, int map_id) {
    std::multimap<int, Map*>::iterator i;
    for (i = _arrMap.lower_bound(world); i != _arrMap.upper_bound(world); i++) {
	       if (i->second->getId() == map_id) {
                _currentMap = i->second;
                return _currentMap;
	       }
    }
    return NULL;
}

void MapManager::loadMapList(const std::string *path) {
    DIR * worlddir = opendir(path->c_str());
    if (worlddir != NULL) {
        struct dirent *worldent, *mapent;
        int world_num = 0;

        while ((worldent = readdir(worlddir)) != NULL) {
            if (worldent->d_type==DT_DIR) {
                std::string temp_path = *path;
                temp_path += "/";
                temp_path += worldent->d_name;

                DIR *mapdir = opendir(temp_path.c_str());
                if (mapdir != NULL) {
                    world_num++;
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
                            _arrMap.insert(std::pair<int, Map*>(world_num, new Map(path, _next_id)));
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

std::vector<Map*> MapManager::getWorld(int world) {
    std::vector<Map*> mapList;
    std::multimap<int, Map*>::iterator i;
    for (i = _arrMap.lower_bound(world); i != _arrMap.upper_bound(world); i++) {
	       mapList.push_back(i->second);
    }
    return mapList;
}
