#include "EventManager.h"

EventManager::EventManager(sf::RenderWindow* app, sf::View game_view, sf::View interface_view) {
    _app = app;
    _game_camera = new Camera(game_view);
    _interface_view = interface_view;
    _playing = true;
    _paused = false;
    _winner = false;
    _loosed = false;
}

void EventManager::manageEvent() {
    sf::Event Event;

    while (_app->GetEvent(Event))  {
        if (Event.Type == sf::Event::Closed || (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape)) {
            _playing = false;
        } else if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::P) {
            _paused = !_paused;
        } else if (Event.Type == sf::Event::MouseWheelMoved && Event.MouseWheel.Delta > 0) { //Zoom in
            _game_camera->zoomIn();
        } else if (Event.Type == sf::Event::MouseWheelMoved && Event.MouseWheel.Delta < 0) { //Zoom out
            _game_camera->zoomOut();
        } else if (Event.Type == sf::Event::MouseButtonPressed && Event.MouseButton.Button == sf::Mouse::Left) {
            EntityManager::Instance()->clic(_app->ConvertCoords(_app->GetInput().GetMouseX(), _app->GetInput().GetMouseY()));
        }
    }
    sf::Vector2f mousePosition = _app->ConvertCoords(_app->GetInput().GetMouseX(), _app->GetInput().GetMouseY());

    if (_game_camera->getRect().Left > 0 && mousePosition.x <  _game_camera->getRect().Left + MARGIN) {
        _game_camera->move(0);
    } else if (mousePosition.x > _game_camera->getRect().GetWidth() - MARGIN && _game_camera->getRect().Right < Config::Instance()->width) {
        _game_camera->move(1);
    }

    _app->SetView(_game_camera->getView());
}

bool EventManager::isPlaying() {
    return _playing;
}

bool EventManager::isPaused() {
    return _paused;
}

sf::View& EventManager::getInterfaceView() {
    return _interface_view;
}

Camera* EventManager::getCamera() {
    return _game_camera;
}
