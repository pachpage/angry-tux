#include "Tux.h"

Tux::Tux(sf::RenderWindow* app
            ,sf::Vector2i& position
            ,std::string& path
            ,int type
            ,b2World* world) : Entity(app, position, path = "tuxs/" + path, 0){
    _type = type;

    //Physics definition
    b2BodyDef bd;
	bd.position.Set(_position.x, _position.y);
    bd.type = b2_dynamicBody;
    bd.angularDamping = 0.01f;

    b2CircleShape circle;
    circle.m_radius = _image->GetWidth() / 2.0f;

    b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 100.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.3f;
	fixtureDef.filter.groupIndex = -type;

	_tuxBody = world->CreateBody(&bd);
    _tuxBody->CreateFixture(&fixtureDef);

    b2MassData mass_data;
    mass_data.center = b2Vec2(0,0);
    mass_data.mass = 20.0f;
    mass_data.I = 50.0f;
    _tuxBody->SetMassData(&mass_data);

    _sprite.SetCenter(_image->GetWidth()/2, _image->GetHeight()/2);
}

Tux::~Tux() {
}

void Tux::mouseReleased(sf::Vector2f firstPosition, sf::Vector2f secondPosition, float time_elapse) {
    firstPosition = Conversion::to_sfmlcoord(firstPosition);
    secondPosition = Conversion::to_sfmlcoord(secondPosition);

    sf::Vector2f thirdPoint(firstPosition.x - 100, firstPosition.y);

    if (secondPosition.y > firstPosition.y
       ) { // && secondPosition.x > thirdPoint.x
        float AC = std::sqrt(std::pow(secondPosition.x - thirdPoint.x, 2) + std::pow(secondPosition.y - thirdPoint.x,2));
        float AB = firstPosition.x - thirdPoint.x;
        float BC = secondPosition.y - firstPosition.y;
        int K = 1000000;
        std::cout << AB/AC*K << " " << BC/AC*K << std::endl;
        b2Vec2 force = b2Vec2(AB/AC*K, BC/AC*K);
        //_tuxBody->ApplyLinearImpulse(force, _tuxBody->GetWorldCenter());
        _tuxBody->ApplyForce(force, _tuxBody->GetWorldCenter());
    }
}

void Tux::render() {
    sf::Vector2i position_sfml = Conversion::to_sfmlcoord(_tuxBody->GetPosition().x, _tuxBody->GetPosition().y);
    _sprite.SetPosition(position_sfml.x, position_sfml.y);
    _sprite.SetRotation(Conversion::to_degres(_tuxBody->GetAngle()));

    _app->Draw(_sprite);
}
