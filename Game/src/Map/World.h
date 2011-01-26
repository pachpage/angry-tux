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
#ifndef WORLD_H
#define WORLD_H
#include "../Utilities/Config.h"

class World {
    private :
        std::string _directory
                    ,_name;
        sf::Image *_image;
        sf::Sprite _sprite;


    public :
        World(std::string directory, std::string name, std::string file_name);
        std::string& getDirectory();
        std::string& getName();
        sf::Sprite& getSprite();
};

#endif
