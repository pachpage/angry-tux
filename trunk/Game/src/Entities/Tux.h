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
#ifndef TUX_H
#define TUX_H
#include "Entity.h"
#include <Box2D/Box2D.h>
#include "../Utilities/Algorithm.h"

class Tux : public Entity
{
    public:
        Tux(sf::RenderWindow* app
            ,sf::Vector2i& position
            ,std::string& path
            ,int type
            ,b2World* world);
        virtual ~Tux();
        void mouseReleased(sf::Vector2f firstPosition, sf::Vector2f secondPosition, float time_elapse);
        void render();
    private:
        b2Body* _tuxBody;
        int _type;
        bool _fire;
        b2Vec2 _force;
        int cpt;
        sf::Clock _timer;
};

#endif // TUX_H
