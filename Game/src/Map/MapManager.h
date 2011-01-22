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
#include "Map.h"
#include <dirent.h>

class MapManager : public CSingleton<MapManager>
{
    public:
        void init();
        void load(const int world, const std::string& path);
        void next(const std::string& path = "");
        void stop();
        void loadMapList(std::string *path);
    protected:
    private:
        MapManager();
        virtual ~MapManager();
        friend class CSingleton<MapManager>;
        std::multimap<int, Map*> _arrMap;
        Map* _currentMap;
};

#endif // MAPMANAGER_H
