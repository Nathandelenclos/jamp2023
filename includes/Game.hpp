/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Game.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.hpp"
#include "Text.hpp"

class Game {
public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
private:
    sf::RenderWindow window;
    std::vector<Object> objects;
    std::vector<Text> texts;
    sf::Event event{};
    sf::Clock clock;
    float deltaTime{};
    float fps;
};
