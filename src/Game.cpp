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

Game::Game() : windowWidth(1000),
               windowHeight(1000),
               window(sf::VideoMode(1000, 1000), "Fact2D") {
    genereateTextures();
    generateGrid();
    generateText();
    viewPosition.x = GridConfig::GRID_SIZE * GridConfig::SQUARE_SIZE / 2;
    viewPosition.y = GridConfig::GRID_SIZE * GridConfig::SQUARE_SIZE / 2;
    std::cout << "generateGrid" << std::endl;
    std::cout << "view.setSize" << std::endl;
    std::cout << "view.setCenter" << std::endl;
    window.setFramerateLimit(60);
    std::cout << "window.setView" << std::endl;
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
        sf::Time time = clock.restart();
        deltaTime = time.asSeconds();
        fps = 1.0f / deltaTime;
    }
}

void Game::update() {
    for (auto &row: grid) {
        for (auto &caseObj: row) {
            caseObj.update(event, deltaTime);
        }
    }
    for (auto &object: objects)
        object.update(event, deltaTime);
}

void Game::render() {
    window.clear();
    for (auto &row: grid) {
        for (auto &caseObj: row) {
            caseObj.draw(window);
        }
    }
    for (auto &text: texts) {
        text.draw(window);
    }

    // sf::Font font;
    // if (!font.loadFromFile("./assets/police.ttf")) {
    //     // Handle font loading failure
    //     return;
    // }

    // // Create a text object
    // sf::Text text;
    // text.setFont(font);
    // text.setString("Hello, SFML!");
    // text.setCharacterSize(24);
    // text.setFillColor(sf::Color::White);
    // text.setStyle(sf::Text::Bold);
    // text.setPosition(100, 100);
    // window.draw(text);
    generateText();
    window.display();
}


void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {

        }

    }
}

void Game::generateGrid() {
    std::cout << "resize" << std::endl;
    for (int i = 0; i < GridConfig::GRID_SIZE; ++i) {
        std::vector<Case> row;
        for (int j = 0; j < GridConfig::GRID_SIZE; ++j) {
            int x = j * GridConfig::SQUARE_SIZE;
            int y = i * GridConfig::SQUARE_SIZE;
            std::cout << "x: " << x << " y: " << y << std::endl;
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
    std::cout << "grid.size()" << grid.size() << "grid[0].size()" << grid[0].size() << std::endl;
}

void Game::genereateTextures() {
    textures["rock"] = sf::Texture();
    textures["rock"].loadFromFile("./assets/rock.jpg");
    textures["dirt"] = sf::Texture();
    textures["dirt"].loadFromFile("./assets/dirt.jpg");
    textures["copper"] = sf::Texture();
    textures["copper"].loadFromFile("./assets/copper.jpg");
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