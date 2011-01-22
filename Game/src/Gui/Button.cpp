#include "Button.h"

GUI::Button::Button(sf::RenderWindow *parentWindow) : Component(parentWindow) {
    _buttonBackground[0] = _backgroundImg;
    _buttonBackground[1] = NULL;
    _buttonBackground[2] = NULL;

    _text.SetFont(sf::Font::GetDefaultFont());
    _text.SetColor(sf::Color(255,255,255));
    _text.SetSize(30);
}

GUI::Button::~Button() {
}

void GUI::Button::SetPosition(const sf::Vector2f& position) {
    GUI::Component::SetPosition(position.x, position.y);
    sf::Vector2<float> textPos(position.x+GetSize().x/2 - _text.GetRect().GetWidth()/2,
                                position.y+GetSize().y/2 - _text.GetRect().GetHeight()/2);
    _text.SetPosition(textPos);
}

void GUI::Button::SetPosition(float x, float y) {
    SetPosition(sf::Vector2f(x, y));
}

void GUI::Button::SetText(const std::string text) {
    _text.SetText(text);
}

void GUI::Button::SetText(const std::string text, const sf::Vector2i position) {
    _text.SetText(text);
    _text.SetPosition(GetPosition().x + position.x, GetPosition().y + position.y);
}

void GUI::Button::SetBackground(const std::string back_img, const std::string hover_img, const std::string clicked_img) {
    GUI::Component::SetBackground(back_img);
    _buttonBackground[0] = _backgroundImg;
    _buttonBackground[1] = RessourceManager::Instance()->GetImage(hover_img);
    _buttonBackground[2] = RessourceManager::Instance()->GetImage(clicked_img);
}

void GUI::Button::SetHoverImage(const std::string img) {
     _buttonBackground[1] = RessourceManager::Instance()->GetImage(img);
}

void GUI::Button::SetClickedImage(const std::string img) {
    _buttonBackground[2] = RessourceManager::Instance()->GetImage(img);
}

void GUI::Button::SetTextSize(float size) {
    _text.SetSize(size);
}

void GUI::Button::SetTextColor(const sf::Color& color) {
    _text.SetColor(color);
}

void GUI::Button::SetTextFont(const sf::Font& font) {
    _text.SetFont(font);
}

void GUI::Button::Move(const sf::Vector2i move) {
    SetPosition(GetPosition().x + move.x, GetPosition().y + move.y);
}

std::string GUI::Button::GetText() const {
    return _text.GetText();
}

void GUI::Button::MousePressed() {
    if (_buttonBackground[2] != NULL) {
        SetImage(*_buttonBackground[2]);
    }
}

void GUI::Button::MouseHover() {
    if (_buttonBackground[1] != NULL) {
        SetImage(*_buttonBackground[1]);
    }
}

void GUI::Button::MouseLeft() {
    if (_buttonBackground[0] != NULL) {
        SetImage(*_buttonBackground[0]);
    }
}

void GUI::Button::Show() {
    _parentRenderWindow->Draw(*this);
    _parentRenderWindow->Draw(_text);
}
