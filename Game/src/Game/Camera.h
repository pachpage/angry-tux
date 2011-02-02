#ifndef CAMERA_H
#define CAMERA_H
#define ZOOM_DELTA 100
#define CAMERA_SPEED 5
#define MARGIN 50
#include "../Utilities/Config.h"

    class Camera
    {
        private :
            sf::View _camera;
            sf::Clock _timer;
        public :
            Camera(sf::View camera);
            void zoomIn();
            void zoomOut();
            void move(int direction);
            void slide(sf::Vector2i dest);
            void setSize(sf::Vector2i size);
            sf::FloatRect getRect();
            sf::View& getView();
    };

#endif
