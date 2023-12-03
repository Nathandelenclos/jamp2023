/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Game.hpp
*/

#include "Game.hpp"
#include "GridConfig.hpp"
#include <cstdlib>

Game::Game() : window(sf::VideoMode(800, 600), "SFML window"), viewPosition(0, 0) {
    generateGrid();
    view.setSize(sf::Vector2f(window.getSize()));
    view.setCenter(viewPosition.x * GridConfig::SQUARE_SIZE, viewPosition.y * GridConfig::SQUARE_SIZE);
    window.setView(view);
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
    for (auto &row : grid) {
        for (auto &caseObj : row) {
            caseObj.draw(window);
        }
    }
    for (auto &text : texts) {
        text.draw(window);
    }
    window.display();
}


void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            moveView(event.key.code);
        }
    }
}

void Game::generateGrid() {
    grid.resize(GridConfig::GRID_SIZE, std::vector<Case>(GridConfig::GRID_SIZE));
    for (int i = 0; i < GridConfig::GRID_SIZE; ++i) {
        for (int j = 0; j < GridConfig::GRID_SIZE; ++j) {
            float x = j * GridConfig::SQUARE_SIZE;
            float y = i * GridConfig::SQUARE_SIZE;
            float randomValue = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
            if (randomValue < GridConfig::ROCK_PROBABILITY) {
                grid[i][j] = Case(x, y, "./assets/rock.jpg");
            } else if (randomValue < GridConfig::ROCK_PROBABILITY + GridConfig::DIRT_PROBABILITY) {
                grid[i][j] = Case(x, y, "./assets/dirt.jpg");
            } else {
                grid[i][j] = Case(x, y, "./assets/copper.jpg");
            }
        }
    }
}

void Game::moveView(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Up:
            viewPosition.y -= 1;
            break;
        case sf::Keyboard::Down:
            viewPosition.y += 1;
            break;
        case sf::Keyboard::Left:
            viewPosition.x -= 1;
            break;
        case sf::Keyboard::Right:
            viewPosition.x += 1;
            break;
        default:
            break;
    }
    clampViewPosition();
}

void Game::clampViewPosition() {
    if (viewPosition.x < 0) viewPosition.x = 0;
    if (viewPosition.y < 0) viewPosition.y = 0;
    if (viewPosition.x >= GridConfig::GRID_SIZE) viewPosition.x = GridConfig::GRID_SIZE - 1;
    if (viewPosition.y >= GridConfig::GRID_SIZE) viewPosition.y = GridConfig::GRID_SIZE - 1;
    view.setCenter(viewPosition.x * GridConfig::SQUARE_SIZE, viewPosition.y * GridConfig::SQUARE_SIZE);
}
