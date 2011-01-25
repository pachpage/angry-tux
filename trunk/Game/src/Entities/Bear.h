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
#ifndef BEAR_H
#define BEAR_H
#include "Entity.h"
#include <Box2D/Box2D.h>

class Bear : public Entity
{
    public:
        Bear(sf::RenderWindow* app
            ,sf::Vector2i& position
            ,std::string& path
            ,int size
            ,int score
            ,b2World* world);
        virtual ~Bear();

        void render();
    protected:
    private:
        b2Body* _bearBody;
        int _score;
        int _size;
};

#endif // BEAR_H
