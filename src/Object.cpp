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

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
            y -= 100 * deltaTime;
        if (event.key.code == sf::Keyboard::Down)
            y += 100 * deltaTime;
        if (event.key.code == sf::Keyboard::Left)
            x -= 100 * deltaTime;
        if (event.key.code == sf::Keyboard::Right)
            x += 100 * deltaTime;
    }
    sprite.setPosition(x, y);
}

void Object::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
