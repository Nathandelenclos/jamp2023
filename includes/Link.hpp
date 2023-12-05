/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Engine.hpp"
#include <ctime>

class Link {
public:
    Link(Engine *engine1, Engine *engine2);
    ~Link();
    Link(const Link &obj);
    void update(int *&money, int moneyObjective);
    void draw(sf::RenderWindow &window);
    friend std::ostream& operator<<(std::ostream&, const Link&);
    Engine *engine1;
    Engine *engine2;
    sf::Vector2f pointA;
    sf::Vector2f pointB;
    sf::VertexArray line;
    sf::Clock clock;
    time_t time;
};
