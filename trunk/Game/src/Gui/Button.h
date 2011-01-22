#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H
#include "Component.h"

namespace GUI
{
    class Button : public Component
    {
        private :
            sf::Image* _buttonBackground[3];

        protected :
            sf::String _text;

        public :
            Button(sf::RenderWindow *parentWindow);
            ~Button();

            void SetPosition(const sf::Vector2f& position);
            void SetPosition(float x, float y);
            void SetText(const std::string text);
            void SetText(const std::string text, const sf::Vector2i position);
            void SetBackground(const std::string back_img, const std::string hover_img, const std::string clicked_img);
            void SetHoverImage(const std::string img);
            void SetClickedImage(const std::string img);
            void SetTextSize(float size);
            void SetTextColor(const sf::Color& color);
            void SetTextFont(const sf::Font& font);
            void Move(const sf::Vector2i move);
            std::string GetText() const;

            void MousePressed();
            void MouseHover();
            void MouseLeft();

            void Show();
    };
}

#endif
