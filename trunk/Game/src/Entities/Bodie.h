#ifndef BODIE_H
#define BODIE_H
#include "Entity.h"

class Bodie : public Entity
{
    public:
        Bodie(sf::RenderWindow* app, sf::Vector2i& position, std::string& path);
        virtual ~Bodie();
    protected:
    private:
};

#endif // BODIE_H
