/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Object.hpp
*/

#pragma once

#include "Object.hpp"

enum EngineType {
    DRILL, FORGE, INDUSTRY
};

class Engine : public Object {
public:
    Engine(float x, float y, EngineType type, sf::Texture &texture);
    ~Engine();
    void update(sf::Event event, float deltaTime) override;
    friend std::ostream& operator<<(std::ostream&, const Engine&);
    void setColor(sf::Color color);
    EngineType type;
};
