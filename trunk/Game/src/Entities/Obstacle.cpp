#include "Obstacle.h"

Obstacle::Obstacle(sf::RenderWindow* app
                ,sf::Vector2i& position
                ,std::string& path
                ,sf::Vector2i& dimension
                ,float angle
                ,bool repeat_x
                ,bool repeat_y
                ,std::string color
                ,b2World* world) : Texture(app, position, path, dimension, angle, repeat_x, repeat_y, color) {

    b2BodyDef obsBodyDef;
	obsBodyDef.position.Set(position.x, position.y);
	_obsBody = world->CreateBody(&obsBodyDef);
	b2PolygonShape obsBox;
    obsBox.SetAsBox(_dimension.x/2.0f, _dimension.y/2.0f);
	_obsBody->CreateFixture(&obsBox, 0.0f);
}

Obstacle::~Obstacle() {
}
