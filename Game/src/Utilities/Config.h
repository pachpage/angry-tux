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
#ifndef CONFIG_H
#define CONFIG_H

#include "Singleton.h"
#include "Logger.h"
#include "RessourceManager.h"

class Config : public CSingleton<Config>
{
    public:
        int width, height, colors, fps, map_width, map_height;
        bool fullscreen, debug;
        std::string image_path, maps_path;
        void init();
    protected:
    private:
        Config();
        virtual ~Config();
        friend class CSingleton<Config>;
};

#endif // CONFIG_H
