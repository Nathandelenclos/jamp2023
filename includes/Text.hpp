/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Text {
public:
    Text(const std::string &text, float x, float y);
    Text(const std::string &text, float x, float y, int size);
    Text(const std::string &text, float x, float y, int size, sf::Color color);
    Text(const std::string &text, float x, float y, int size, sf::Color color, sf::Uint32 style);
    Text(const std::string &text, float x, float y, int size, sf::Color color, sf::Uint32 style, std::string &fontFile);
    Text(const Text &obj);
    ~Text();
    void update(std::string &text);
    void update(std::string &text, float x, float y);
    void draw(sf::RenderWindow &window);

private:
    float x;
    float y;
    sf::Text sprite;
    sf::Font font;
};
