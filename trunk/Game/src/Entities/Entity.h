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
#ifndef ENTITY_H
#define ENTITY_H
#include "../Utilities/Config.h"
#include "../Utilities/Conversion.h"

class Entity
{
    public:
        Entity(sf::RenderWindow* app
               ,sf::Vector2i& position
               ,std::string& path
               ,float angle);
        virtual ~Entity();
        virtual void render()=0;

    protected:
        sf::RenderWindow *_app;
        sf::Vector2i _position;
        sf::Image* _image;
        sf::Sprite _sprite;
    private:
};

#endif // ENTITY_H
