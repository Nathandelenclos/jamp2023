/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Game.hpp
*/

#include "Game.hpp"
#include "GridConfig.hpp"
#include <cstdlib>

Game::Game() : windowWidth(800),
               windowHeight(600),
               window(sf::VideoMode(800, 600), "Fact2D"),
               viewPosition(0, 0),
               view(sf::FloatRect(-400, -300, 800, 600)) {
    std::cout << "Game constructor" << std::endl;
    genereateTextures();
    generateGrid();
    std::cout << "generateGrid" << std::endl;
    std::cout << "view.setSize" << std::endl;
    std::cout << "view.setCenter" << std::endl;
    window.setView(view);
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
    for (auto &object: objects)
        object.update(event, deltaTime);
}

void Game::render() {
    window.clear();
    view.setCenter(viewPosition);
    window.setView(view);
    for (auto &row: grid) {
        for (auto &caseObj: row) {
            caseObj.draw(window);
        }
    }
    for (auto &text: texts) {
        text.draw(window);
    }
    window.display();
}


void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            moveView(event.key.code);
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
                row.emplace_back(x, y, textures["rock"]);
            } else if (randomValue < GridConfig::ROCK_PROBABILITY + GridConfig::DIRT_PROBABILITY) {
                row.emplace_back(x, y, textures["dirt"]);
            } else {
                row.emplace_back(x, y, textures["copper"]);
            }
        }
        grid.push_back(row);
    }
    std::cout << "grid.size()" << grid.size() << "grid[0].size()" << grid[0].size() << std::endl;
}

void Game::moveView(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Up:
            viewPosition.y -= velocity * deltaTime;
            break;
        case sf::Keyboard::Down:
            viewPosition.y += velocity * deltaTime;
            break;
        case sf::Keyboard::Left:
            viewPosition.x -= velocity * deltaTime;
            break;
        case sf::Keyboard::Right:
            viewPosition.x += velocity * deltaTime;
            break;
        default:
            break;
    }
    std::cout << "viewPosition.x: " << viewPosition.x << " viewPosition.y: " << viewPosition.y << std::endl;
//    clampViewPosition();
}

void Game::clampViewPosition() {
//    if (viewPosition.x < 0) viewPosition.x = 0;
//    if (viewPosition.y < 0) viewPosition.y = 0;
//    if (viewPosition.x >= GridConfig::GRID_SIZE) viewPosition.x = GridConfig::GRID_SIZE - 1;
//    if (viewPosition.y >= GridConfig::GRID_SIZE) viewPosition.y = GridConfig::GRID_SIZE - 1;
    view.setCenter(viewPosition);
    window.setView(view);
}

void Game::genereateTextures() {
    textures["rock"] = sf::Texture();
    textures["rock"].loadFromFile("./assets/rock.jpg");
    textures["dirt"] = sf::Texture();
    textures["dirt"].loadFromFile("./assets/dirt.jpg");
    textures["copper"] = sf::Texture();
    textures["copper"].loadFromFile("./assets/copper.jpg");
}
