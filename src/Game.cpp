/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Game.hpp
*/

#include "Game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "SFML window") {
    objects.emplace_back(0, 0, "../assets/Fuel_Generator.png");
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

void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    for (auto &object: objects)
        object.update(event, deltaTime);
}

void Game::render() {
    window.clear();
    for (auto &object: objects)
        object.draw(window);
    for (auto &text: texts)
        text.draw(window);
    window.display();
}
