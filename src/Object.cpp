/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#include "Object.hpp"

Object::Object(float x, float y, const std::string& texturePath) : x(x), y(y)
{
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Object::Object(const Object &obj) : x(obj.x), y(obj.y)
{
    texture = obj.texture;
    sprite = obj.sprite;
    sprite.setPosition(x, y);
    std::cout << x << " " << y << std::endl;
    std::cout << "Object copy constructor" << std::endl;
}

Object::~Object() = default;

void Object::update(sf::Event event, float deltaTime)
{

}

void Object::draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

Object::Object(float x, float y, sf::Texture &texture): x(x), y(y) {
    std::cout << "Object constructor with texture x= " << x << " y= " << y << std::endl;
    this->texture = texture;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

}
