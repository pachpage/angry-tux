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
#ifndef _CONVERSION_H
#define	_CONVERSION_H

#ifndef PI
    #define PI (3.14159265358979323846)
#endif
#include "Config.h"

class Conversion {
    public:
        static float to_degres(float angle);

        static float to_radian(float angle);

        static sf::Vector2i to_sfmlcoord(sf::Vector2i position);

        static sf::Vector2f to_sfmlcoord(sf::Vector2f position);

        static sf::Vector2i to_sfmlcoord(int x, int y);

    private:
        Conversion();
};

#endif
