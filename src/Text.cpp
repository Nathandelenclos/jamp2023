/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Game.hpp
*/

#include "Text.hpp"

Text::Text(const std::string &text, float x, float y) : x(x), y(y)
{
    if (!font.loadFromFile("./assets/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
    sprite.setFont(font);
    sprite.setString(text);
    sprite.setCharacterSize(24);
    sprite.setFillColor(sf::Color::White);
    sprite.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

Text::Text(const std::string &text, float x, float y, int size) : x(x), y(y)
{
    if (!font.loadFromFile("./assets/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
    sprite.setFont(font);
    sprite.setString(text);
    sprite.setCharacterSize(size);
    sprite.setFillColor(sf::Color::White);
    sprite.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

Text::Text(const std::string &text, float x, float y, int size, sf::Color color) : x(x), y(y)
{
    if (!font.loadFromFile("./assets/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
    sprite.setFont(font);
    sprite.setString(text);
    sprite.setCharacterSize(size);
    sprite.setFillColor(color);
    sprite.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

Text::Text(const std::string &text, float x, float y, int size, sf::Color color, sf::Uint32 style) : x(x), y(y)
{
    if (!font.loadFromFile("./assets/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
    sprite.setFont(font);
    sprite.setString(text);
    sprite.setCharacterSize(size);
    sprite.setFillColor(color);
    sprite.setStyle(style);
}

Text::Text(const std::string &text, float x, float y, int size, sf::Color color, sf::Uint32 style, std::string &fontFile) : x(x), y(y)
{
    if (!font.loadFromFile(fontFile))
        std::cout << "Error loading font" << std::endl;
    sprite.setFont(font);
    sprite.setString(text);
    sprite.setCharacterSize(size);
    sprite.setFillColor(color);
    sprite.setStyle(style);
}

Text::Text(const Text &obj) : x(obj.x), y(obj.y)
{
    if (!font.loadFromFile("./assets/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
    sprite.setFont(font);
    sprite.setString("Hello world");
    sprite.setCharacterSize(24);
    sprite.setFillColor(sf::Color::White);
    sprite.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

Text::~Text() = default;

void Text::update(std::string &text) {
    sprite.setString(text);
}

void Text::update(std::string &text, float x, float y)
{
    sprite.setString(text);
    sprite.setPosition(x, y);
}

void Text::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
