//Tanguy Arnaud

#ifndef GUI_COMPONENT_H
#define GUI_COMPONENT_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../Utilities/RessourceManager.h"

namespace GUI {

    class Component : public sf::Sprite
    {
        private :
        	void (*_clickCallback)();
            void (*_mouseHoverCallback)();
            bool _mouseIn;

            void ManageMouse();

        protected :
            sf::RenderWindow *_parentRenderWindow;
            sf::Image *_backgroundImg;
            sf::Event _event;

            virtual void MousePressed();
            virtual void MouseReleased();
            virtual void MouseHover();
            virtual void MouseLeft();

        public :
            Component(sf::RenderWindow *parentWindow);
            virtual ~Component();

            void SetBackground(const std::string path);
            void SetBackgroundColor(const sf::Color &color);

            void CheckEvent(sf::Event Event);
            void SetClickCallback(void(*)());
            void SetMouseHoverCallback(void(*)());

    };
}

#endif
