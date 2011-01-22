#include "Component.h"

GUI::Component::Component(sf::RenderWindow *parentWindow) {
    _mouseHoverCallback = NULL;
    _clickCallback = NULL;
    _mouseIn = false;
}

GUI::Component::~Component() {
}

void GUI::Component::SetBackground(const std::string path) {
    _backgroundImg = RessourceManager::Instance()->GetImage(path);
    SetImage(*_backgroundImg);
}

void GUI::Component::SetBackgroundColor(const sf::Color &color) {
    SetColor(color);
}

void GUI::Component::CheckEvent(sf::Event Event) {
    _event= Event;
    if (_event.Type == sf::Event::MouseButtonPressed
        || _event.Type == sf::Event::MouseButtonReleased
        || _event.Type == sf::Event::MouseMoved) {

        ManageMouse();
    }
}

void GUI::Component::SetClickCallback(void(*clickCallBack)()) {
    _clickCallback = clickCallBack;
}

void GUI::Component::SetMouseHoverCallback(void(*mouseHoverCallback)()) {
    _mouseHoverCallback = mouseHoverCallback;
}

void GUI::Component::ManageMouse() {
    unsigned int mouseX = _parentRenderWindow->GetInput().GetMouseX();
    unsigned int mouseY = _parentRenderWindow->GetInput().GetMouseY();
    sf::Rect<int> objectRect(GetPosition().x, GetPosition().y, GetPosition().x+GetSize().x, GetPosition().y+GetSize().y);

    if (objectRect.Contains(mouseX, mouseY)) {
        _mouseIn = true;
        if (_event.Type == sf::Event::MouseButtonPressed) {
            if (_mouseHoverCallback != NULL) {
                (*_mouseHoverCallback)();
            }
            MousePressed();
        } else if (_event.Type == sf::Event::MouseButtonReleased) {
            MouseReleased();
        } else if (_event.Type == sf::Event::MouseMoved) {
            if (_clickCallback != NULL) {
                (*_clickCallback)();
            }
            MouseHover();
        }
    } else if(_mouseIn){
        _mouseIn = false;
        MouseLeft();
    }
}

void GUI::Component::MousePressed() {
}

void GUI::Component::MouseReleased() {
}

void GUI::Component::MouseHover() {
}

void GUI::Component::MouseLeft() {
}
