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
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "../Utilities/Config.h"
#include "Texture.h"
#include "Obstacle.h"
#include "Bar.h"
#include <Box2D/Box2D.h>
#include <vector>

class EntityManager : public CSingleton<EntityManager>
{
    public:
        void init(sf::RenderWindow* app
                  ,b2World* world);

        void loadTexture(int layer_position
                         ,std::string str_class
                         ,sf::Vector2i position
                         ,std::string path_texture
                         ,sf::Vector2i dimension
                         ,float angle
                         ,bool repeat_x
                         ,bool repeat_y
                         ,std::string color);

        void loadBar (sf::Vector2i position
                         ,std::string path_texture
                         ,sf::Vector2i dimension
                         ,float angle
                         ,int type);

        void loadBear (sf::Vector2i position
                         ,std::string path_texture
                         ,int size
                         ,int score);

        void loadTux (sf::Vector2i position
                      ,std::string path_texture
                      ,int type);

        void render();

        void stop();
    protected:
    private:
        EntityManager();
        ~EntityManager();
        friend class CSingleton<EntityManager>;
        std::multimap<int, Texture*> _arrTexture;
        std::vector<Bar*> _arrBar;

        sf::RenderWindow* _app;
        b2World* _world;
        int _layer_count;
};

#endif // ENTITYMANAGER_H
