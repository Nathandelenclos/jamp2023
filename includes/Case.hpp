/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Case.hpp
*/

#pragma once

#include "Object.hpp"

enum CaseType {
    COPPER, DIRT, ROCK, OTHER
};

class Case : public Object {
public:
    Case(float x, float y, const std::string& texturePath);
    Case(float x, float y, CaseType type, sf::Texture &texture);
    ~Case();
    void update(sf::Event event, float deltaTime) override;
    CaseType type;
    friend std::ostream& operator<<(std::ostream&, const Case&);

};
