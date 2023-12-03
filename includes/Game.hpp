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
#include "Engine.hpp"

class Game {
public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
    void generateGrid();
    void generateText();
    void generateTextures();


private:
    sf::RenderWindow window;
    std::vector<Object> objects;
    sf::Event event{};
    sf::Clock clock;
    float deltaTime{};
    std::vector<std::vector<Case>> grid;
    sf::Vector2<float> viewPosition;
    std::map<std::string, sf::Texture> textures;
    Engine *attachedMouse;
    std::vector<Engine> engines;
    std::vector<sf::Text> texts;
    static std::string input;
};
