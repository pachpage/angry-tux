/*
    Copyright (C) 2010  Nicolas Beaudrot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MAPMANAGER_H
#define MAPMANAGER_H
#include "../Utilities/Singleton.h"
#include <map>
#include <dirent.h>
#include "World.h"
#include "Map.h"

class MapManager : public CSingleton<MapManager>
{
    public:
        void init();
        Map* setMap(const std::string &world, int map_id);
        Map* setNextMap();
        void stop();
        void loadMapList(const std::string *path);
        void loadWorldList(const std::string path);
        std::vector<Map*> getWorldMaps(const std::string& world);
        std::vector<World*>& getWorlds();
        Map* getCurrentMap();
    protected:
    private:
        MapManager();
        virtual ~MapManager();
        friend class CSingleton<MapManager>;
        std::multimap<std::string, Map*> _arrMap;
        std::vector<World*> _arrWorld;
        Map* _currentMap;
        int _next_id;
};

#endif // MAPMANAGER_H
