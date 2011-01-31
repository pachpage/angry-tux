#include "Camera.h"

Camera::Camera(sf::View camera) {
    _camera = camera;
}

void Camera::zoomIn() {
    if (_camera.GetRect().GetHeight() > (Config::Instance()->height/2)) {
        _camera.SetFromRect(sf::FloatRect(0,0,_camera.GetRect().GetWidth() - ZOOM_DELTA,_camera.GetRect().GetHeight() - ZOOM_DELTA));
        _camera.Move(0, Config::Instance()->height - _camera.GetRect().GetHeight());
     }
}

void Camera::zoomOut() {
    if (_camera.GetRect().GetHeight() < Config::Instance()->height) {
        _camera.SetFromRect(sf::FloatRect(0,0,_camera.GetRect().GetWidth() + ZOOM_DELTA,_camera.GetRect().GetHeight() + ZOOM_DELTA));
        _camera.Move(0, Config::Instance()->height - _camera.GetRect().GetHeight());
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
    }
}

void Camera::slide(sf::Vector2i dest) {

}

sf::FloatRect Camera::getRect(){
    return _camera.GetRect();
}

sf::View& Camera::getView() {
    return _camera;
}
