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
    sf::Vector2f z_out(0, _game_view.GetRect().Right);
    //std::cout << _game_view.GetRect().Right << std::endl;
    while (_app->GetEvent(Event))  {
        if (Event.Type == sf::Event::Closed || (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape)) {
            _playing = false;
        } else if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::P) {
            _paused = !_paused;
        } else if (Event.Type == sf::Event::MouseWheelMoved && Event.MouseWheel.Delta > 0) { //Zoom in
             /*_game_view.Zoom(1.1f);
             z_out.x = z_out.x - _game_view.GetRect().Left;
             std::cout << z_out.x << " " << _game_view.GetRect().Left << std::endl;
             _game_view.Move(-z_out.x, -z_out.x);*/
             _game_view.SetFromRect(sf::FloatRect(0,0,400,300));
             _game_view.Move(0,300);
        } else if (Event.Type == sf::Event::MouseWheelMoved && Event.MouseWheel.Delta < 0) { //Zoom out
             /*_game_view.Zoom(0.9f);
             z_out.x = z_out.x - _game_view.GetRect().Left;
             _game_view.Move(z_out.x, -z_out.x);*/
             _game_view.SetFromRect(sf::FloatRect(0,0,800,600));
        }
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
