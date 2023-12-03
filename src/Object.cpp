/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#include "Object.hpp"
#include "GridConfig.hpp"

Object::Object(float x, float y, const std::string &texturePath) : x(x), y(y) {
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Object::Object(const Object &obj) : x(obj.x), y(obj.y) {
    texture = obj.texture;
    sprite = obj.sprite;
    sprite.setPosition(x, y);
}

Object::~Object() = default;

void Object::update(sf::Event event, float deltaTime) {

    static bool isPressed = false;
    sf::Rect<float> bounds = sprite.getGlobalBounds();
    if (event.mouseButton.x >= bounds.left && event.mouseButton.x <= bounds.left + bounds.width &&
        event.mouseButton.y >= bounds.top && event.mouseButton.y <= bounds.top + bounds.height) {
        if (event.type == sf::Event::MouseButtonPressed) {
            isPressed = true;
        }
        if (event.type == sf::Event::MouseButtonReleased && isPressed) {
            std::cout << *this << std::endl;
            isPressed = false;
        }
    }
}

void Object::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

Object::Object(float x, float y, sf::Texture &texture) : x(x), y(y) {
    this->texture = texture;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Object::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
    sprite.setPosition(x, y);
}

std::ostream &operator<<(std::ostream &stream, const Object &object) {
    stream << "Object(" << object.x << ", " << object.y << ")";
    return stream;
}
