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
    Object(float x, float y, const std::string& texturePath);
    Object(float x, float y, sf::Texture &texture);
    Object(const Object &obj);
    ~Object();

    virtual void update(sf::Event event, float deltaTime);
    void draw(sf::RenderWindow &window);
    void setPosition(float x, float y);
    void setScale(float x, float y) { sprite.setScale(x, y); }

protected:
    float x;
    float y;
    std::string texturePath;
    sf::Sprite sprite;
    sf::Texture texture;
};
