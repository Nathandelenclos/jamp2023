/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#include "Object.hpp"

Object::Object() : x(0), y(0)
{
    texture.loadFromFile("./assets/Fuel_Generator.png");
    sprite.setTexture(texture);
}

Object::Object(float x, float y) : x(x), y(y)
{
    texture.loadFromFile("./assets/Fuel_Generator.png");
    sprite.setTexture(texture);
}

Object::Object(float x, float y, const std::string& texturePath) : x(x), y(y)
{
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
}

Object::Object(const Object &obj) : x(obj.x), y(obj.y)
{
    texture.loadFromFile("./assets/Fuel_Generator.png");
    sprite.setTexture(texture);
}

Object::~Object() = default;

void Object::update(sf::Event event, float deltaTime)
{
    sprite.setPosition(x, y);
}

void Object::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
