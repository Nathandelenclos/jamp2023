/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Object {
public:
    Object(float x, float y, const std::string &texturePath);

    Object(float x, float y, sf::Texture &texture);

    Object(const Object &obj);

    ~Object();

    virtual void update(sf::Event event, float deltaTime);

    void draw(sf::RenderWindow &window);

    void setPosition(float x, float y);

    void setOrigin(float x, float y) { sprite.setOrigin(x, y); }

    sf::Vector2f getPosition() { return sprite.getPosition(); }

    sf::Vector2f getSize() { return sprite.getScale(); }

    sf::Rect<float> getBounds() { return sprite.getGlobalBounds(); }

    friend std::ostream &operator<<(std::ostream &, const Object &);

    void setScale(float x, float y) { sprite.setScale(x, y); }

protected:
    float x;
    float y;
    std::string texturePath;
    sf::Sprite sprite;
    sf::Texture texture;
};
