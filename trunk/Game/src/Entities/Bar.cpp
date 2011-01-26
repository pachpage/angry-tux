#include "Bar.h"

Bar::Bar(sf::RenderWindow* app
        ,sf::Vector2i& position
        ,std::string& path
        ,sf::Vector2i dimension
        ,float angle
        ,int type
        ,b2World* world) : Entity(app, position, path = "bars/" + path, angle), _dimension(dimension) {
    _type = type;
    _collide = false;

    //Physics definition
    b2BodyDef bd;
	bd.position.Set(_position.x, _position.y);
    bd.type = b2_dynamicBody;
    bd.angle = -Conversion::to_radian(angle);
    bd.angularDamping = 0.01f;

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(dimension.x/2.0f, dimension.y/2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 100;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.3f;
	fixtureDef.filter.groupIndex = -type;

	_barBody = world->CreateBody(&bd);
    _barBody->CreateFixture(&fixtureDef);

    _sprite.SetCenter(dimension.x/2, dimension.y/2);
}

Bar::~Bar() {
}

void Bar::render() {
    sf::Vector2i position_sfml = Conversion::to_sfmlcoord(_barBody->GetPosition().x, _barBody->GetPosition().y);
    _sprite.SetPosition(position_sfml.x, position_sfml.y);
    _sprite.SetRotation(Conversion::to_degres(_barBody->GetAngle()));

    _app->Draw(_sprite);
}
