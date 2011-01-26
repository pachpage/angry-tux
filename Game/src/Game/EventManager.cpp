#include "EventManager.h"

EventManager::EventManager(sf::RenderWindow* app, sf::View game_view, sf::View interface_view) {
    _app = app;
    _game_view = game_view;
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
             if (_game_view.GetRect().GetHeight() > (Config::Instance()->height/2)) {
                _game_view.SetFromRect(sf::FloatRect(0,0,_game_view.GetRect().GetWidth() - ZOOM_DELTA,_game_view.GetRect().GetHeight() - ZOOM_DELTA));
                _game_view.Move(0, Config::Instance()->height - _game_view.GetRect().GetHeight());
             }
        } else if (Event.Type == sf::Event::MouseWheelMoved && Event.MouseWheel.Delta < 0) { //Zoom out
             if (_game_view.GetRect().GetHeight() < Config::Instance()->height) {
                _game_view.SetFromRect(sf::FloatRect(0,0,_game_view.GetRect().GetWidth() + ZOOM_DELTA,_game_view.GetRect().GetHeight() + ZOOM_DELTA));
                _game_view.Move(0, Config::Instance()->height - _game_view.GetRect().GetHeight());
             }
        }
    }

    if (_app->GetInput().GetMouseX() < MARGIN && _game_view.GetRect().Left > 0) {
        _game_view.Move(-CAMERA_SPEED, 0);
    } else if (_app->GetInput().GetMouseX() > _game_view.GetRect().GetWidth() - MARGIN && _game_view.GetRect().Right < Config::Instance()->width) {
        _game_view.Move(CAMERA_SPEED, 0);
    }

    _app->SetView(_game_view);
    //sf::Vector2f mousePosition = _app.ConvertCoords(_app.GetInput().GetMouseX(), _app.GetInput().GetMouseY());
}

bool EventManager::isPlaying() {
    return _playing;
}

bool EventManager::isPaused() {
    return _paused;
}

sf::View& EventManager::getGameView() {
    return _game_view;
}

sf::View& EventManager::getInterfaceView() {
    return _interface_view;
}
