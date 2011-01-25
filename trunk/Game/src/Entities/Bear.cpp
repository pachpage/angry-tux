#include "Bear.h"

Bear::Bear(sf::RenderWindow* app
            ,sf::Vector2i& position
            ,std::string& path
            ,int size
            ,int score
            ,b2World* world) : Entity(app, position, path = "bears/" + path, 0){

    _score = score;
    _size = size;

    //Physics definition
    b2BodyDef bd;
	bd.position.Set(_position.x, _position.y);
    bd.type = b2_dynamicBody;
    bd.angularDamping = 0.01f;

	b2CircleShape circle;
    circle.m_radius = _image->GetWidth() / 2;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 100;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.3f;

	_bearBody = world->CreateBody(&bd);
    _bearBody->CreateFixture(&fixtureDef);

    _sprite.SetCenter(_image->GetWidth()/2, _image->GetHeight()/2);
}

Bear::~Bear() {

}

void Bear::render() {
    sf::Vector2i position_sfml = Conversion::to_sfmlcoord(_bearBody->GetPosition().x, _bearBody->GetPosition().y);
    _sprite.SetPosition(position_sfml.x, position_sfml.y);
    _sprite.SetRotation(Conversion::to_degres(_bearBody->GetAngle()));

    _app->Draw(_sprite);
}
