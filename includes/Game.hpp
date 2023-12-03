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
#include "Case.hpp"
#include "GridConfig.hpp"

class Game {
public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
    void generateGrid();
    void genereateTextures();

private:
    const float velocity = 9000.0f;
    sf::RenderWindow window;
    int windowWidth;
    int windowHeight;
    std::vector<Object> objects;
    std::vector<Text> texts;
    sf::Event event{};
    sf::Clock clock;
    float deltaTime{};
    float fps;
    std::vector<std::vector<Case>> grid;
    sf::Vector2<float> viewPosition;
    std::map<std::string, sf::Texture> textures;
};
