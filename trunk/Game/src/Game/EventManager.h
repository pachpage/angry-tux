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
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#define MARGIN 50
#include "../Utilities/Config.h"
#include "../Map/MapManager.h"
#include "Camera.h"

class EventManager
{
    private :
        bool _paused
            ,_winner
            ,_loosed
            ,_playing;
        sf::RenderWindow *_app;
        sf::View _interface_view;
        Camera* _game_camera;
    public :
        EventManager(sf::RenderWindow* app, sf::View game_view, sf::View interface_view);
        void manageEvent();
        bool isPlaying();
        bool isPaused();
        sf::View& getInterfaceView();
        Camera* getCamera();
};

#endif
