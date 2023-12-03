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
    void update(sf::Event event, float deltaTime);
    void draw(sf::RenderWindow &window);

protected:
    float x{};
    float y{};
    sf::Sprite sprite;
    sf::Texture texture;
};
