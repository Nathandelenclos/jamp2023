/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Game.hpp
*/

#include "Game.hpp"
#include "GridConfig.hpp"
#include <cstdlib>
#include "Text.hpp"

Game::Game() : window(sf::VideoMode(1000, 1000), "Fact2D") {
    generateTextures();
    generateGrid();
    generateText();
    viewPosition.x = GridConfig::GRID_SIZE * GridConfig::SQUARE_SIZE / 2;
    viewPosition.y = GridConfig::GRID_SIZE * GridConfig::SQUARE_SIZE / 2;
    window.setFramerateLimit(60);
    attachedMouse = nullptr;
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
        sf::Time time = clock.restart();
        deltaTime = time.asSeconds();
    }
}

void Game::update() {
    for (auto &row: grid) {
        for (auto &caseObj: row) {
            caseObj.update(event, deltaTime, attachedMouse);
        }
    }
    for (auto &object: objects)
        object.update(event, deltaTime);

    if (attachedMouse != nullptr) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        attachedMouse->setPosition(mousePos.x, mousePos.y);
    }
}

void Game::render() {
    window.clear();
    for (auto &row: grid) {
        for (auto &caseObj: row) {
            caseObj.draw(window);
        }
    }
    generateText();

    for (auto &object: objects)
        object.draw(window);

    window.display();
}


void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.key.code == sf::Keyboard::A) {
                objects.emplace_back(event.mouseButton.x, event.mouseButton.y, textures["fuel"]);
                attachedMouse = &objects.back();
                attachedMouse->setScale(0.3, 0.3);
            }
        }
    }
}

void Game::generateGrid() {
    for (int i = 0; i < GridConfig::GRID_SIZE; ++i) {
        std::vector<Case> row;
        for (int j = 0; j < GridConfig::GRID_SIZE; ++j) {
            int x = j * GridConfig::SQUARE_SIZE;
            int y = i * GridConfig::SQUARE_SIZE;
            float randomValue = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
            if (randomValue < GridConfig::ROCK_PROBABILITY) {
                row.emplace_back(x, y, CaseType::ROCK, textures["rock"]);
            } else if (randomValue < GridConfig::ROCK_PROBABILITY + GridConfig::DIRT_PROBABILITY) {
                row.emplace_back(x, y, CaseType::DIRT, textures["dirt"]);
            } else {
                row.emplace_back(x, y, CaseType::COPPER,textures["copper"]);
            }
        }
        grid.push_back(row);
    }
}

void Game::generateTextures() {
    textures["rock"] = sf::Texture();
    textures["rock"].loadFromFile("./assets/rock.jpg");
    textures["dirt"] = sf::Texture();
    textures["dirt"].loadFromFile("./assets/dirt.jpg");
    textures["copper"] = sf::Texture();
    textures["copper"].loadFromFile("./assets/copper.jpg");
    textures["fuel"] = sf::Texture();
    textures["fuel"].loadFromFile("./assets/Fuel_Generator.png");
}

void Game::generateText() {

    sf::Font font;
    if (!font.loadFromFile("./assets/police.ttf")) {
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Press 1 = Drill");
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(10, 10);
    sf::Text text2;
    text2.setFont(font);
    text2.setString("Press 2 = Forge");
    text2.setCharacterSize(14);
    text2.setFillColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 30);
    sf::Text text3;
    text3.setFont(font);
    text3.setString("Press 3 = Industry");
    text3.setCharacterSize(14);
    text3.setFillColor(sf::Color::White);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(10, 50);

    window.draw(text);
    window.draw(text2);
    window.draw(text3);
}
