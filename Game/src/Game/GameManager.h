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
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "../Utilities/Config.h"
#include "../Entities/EntityManager.h"
#include "../Map/MapManager.h"

class GameManager : public CSingleton<GameManager>
{
    public:
        void init();
        void newGame(const int world_num, const std::string& path = "");
    protected:
    private:
        GameManager();
        ~GameManager();
        friend class CSingleton<GameManager>;
        sf::RenderWindow _app;
        b2World *_world;
        bool _playing, _paused;
        void createWorld();
        void destroyWorld();
        void run();
};

#endif // GAMEMANAGER_H
