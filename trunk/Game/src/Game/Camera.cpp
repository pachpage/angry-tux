#include "Camera.h"

Camera::Camera(sf::View camera) {
    _camera = camera;
}

void Camera::zoomIn() {
    if (_camera.GetRect().GetHeight() > (Config::Instance()->map_height/2)) {
        _camera.SetFromRect(sf::FloatRect(0,0,_camera.GetRect().GetWidth() - ZOOM_DELTA,_camera.GetRect().GetHeight() - ZOOM_DELTA));
        _camera.Move(0, Config::Instance()->map_height - _camera.GetRect().GetHeight());
     }
}

void Camera::zoomOut() {
    if (_camera.GetRect().GetHeight() < Config::Instance()->map_height) {
        _camera.SetFromRect(sf::FloatRect(0,0,_camera.GetRect().GetWidth() + ZOOM_DELTA,_camera.GetRect().GetHeight() + ZOOM_DELTA));
        _camera.Move(0, Config::Instance()->map_height - _camera.GetRect().GetHeight());
     }
}

void Camera::move(int direction) {
    switch(direction) {
        case 0 :  //Left
            _camera.Move(-CAMERA_SPEED, 0);
            break;
        case 1 : //Right
            _camera.Move(CAMERA_SPEED, 0);
            break;
        case 2 : //Down
            _camera.Move(0, -CAMERA_SPEED);
            break;
        case 3 : //Up
            _camera.Move(0, CAMERA_SPEED);
            break;
    }
}

void Camera::slide(sf::Vector2i dest) {

}

void Camera::setSize(sf::Vector2i size) {
    _camera.SetFromRect(sf::FloatRect(0, 0, size.x, size.y));
}

sf::FloatRect Camera::getRect(){
    return _camera.GetRect();
}

sf::View& Camera::getView() {
    return _camera;
}

