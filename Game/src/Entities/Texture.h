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
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Entity.h"

class Texture : public Entity
{
    public:
        /**
        * Constructor
        */
        Texture(sf::RenderWindow* app
                ,sf::Vector2i& position
                ,std::string& path
                ,sf::Vector2i& dimension
                ,float angle
                ,bool repeat_x
                ,bool repeat_y
                ,std::string color);
        /**
        * Destructor
        */
        virtual ~Texture();

        void render();
    protected:
        sf::Vector2i _dimension;
        bool _repeat_x,
             _repeat_y;
        sf::Shape _shape;
    private:
};

#endif // TEXTURE_H
