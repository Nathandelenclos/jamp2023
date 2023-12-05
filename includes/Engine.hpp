/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#pragma once

#include "Object.hpp"
#include "GridConfig.hpp"

enum EngineType {
    DRILL, FORGE, INDUSTRY
};

class Engine : public Object {
public:
    Engine(float x, float y, EngineType type, sf::Texture &texture);
    ~Engine();
    void update(sf::Event event, float deltaTime, Engine *attachedEngine,  Engine *&linkStart, Engine *&linkEnd);
    friend std::ostream& operator<<(std::ostream&, const Engine&);
    void setColor(sf::Color color);
    EngineType type;
};
