#include "Texture.h"
#include <math.h>
#include <sstream>

Texture::Texture(sf::RenderWindow* app
                ,sf::Vector2i& position
                ,std::string& path
                ,sf::Vector2i& dimension
                ,float angle
                ,bool repeat_x
                ,bool repeat_y
                ,std::string color) : Entity(app, position, path = "textures/" + path, angle), _dimension(dimension) {
    _repeat_x = repeat_x;
    _repeat_y = repeat_y;

    if (color.size() > 0) {
        int colors[3];
        int index = 0;
        std::string temp = "";
        for (unsigned int i=0; i < color.size(); i++) {
            if (color[i] == ',') {
                std::istringstream conv(temp);
                conv >> colors[index];
                temp = "";
                index++;
            } else {
                temp += color[i];
            }
        }
        std::istringstream conv(temp);
        conv >> colors[2];
        _shape = sf::Shape::Rectangle(0, 0, dimension.x, dimension.y, sf::Color(colors[0], colors[1], colors[2]));
        _shape.SetPosition(position.x, Conversion::to_sfmlcoord(position).y);
        _shape.SetRotation(angle);
        _shape.SetCenter(dimension.x/2, dimension.y/2);
    } else {
        _sprite.SetCenter(dimension.x/2, dimension.y/2);
    }
}

Texture::~Texture() {
}

void Texture::render() {
    if (_shape.GetNbPoints() > 0) {
        _app->Draw(_shape);
    } else {
        if (!_repeat_x && !_repeat_y) {
            _app->Draw(_sprite);
        }

        if (_repeat_x && !_repeat_y) {
            float line = ceil(_dimension.x / _image->GetWidth());
            float current_x = 0;

            for(int i = 0; i < line; i++) {
                _sprite.SetPosition(_position.x + current_x, Conversion::to_sfmlcoord(_position).y);
                _app->Draw(_sprite);
                current_x += _image->GetWidth();
            }
        }

        if (!_repeat_x && _repeat_y) {
            float column = ceil(_dimension.y / _image->GetHeight());
            float current_y = 0;

            for (int j=0; j < column; j++) {
                _sprite.SetPosition(_position.x, Conversion::to_sfmlcoord(_position).y + current_y);
                _app->Draw(_sprite);
                current_y += _image->GetHeight();
            }
            _app->Draw(_sprite);
        }

        if (_repeat_x && _repeat_y) {
            float line = ceil(_dimension.x / _image->GetWidth());
            float column = ceil(_dimension.y / _image->GetHeight());
            float current_x = 0;

            for(int i = 0; i < line; i++) {
                float current_y = 0;
                for (int j=0; j < column; j++) {
                    _sprite.SetPosition(_position.x + current_x, Conversion::to_sfmlcoord(_position).y + current_y);
                    _app->Draw(_sprite);
                    current_y += _image->GetHeight();
                }
                current_x += _image->GetWidth();
            }
        }
    }
}
