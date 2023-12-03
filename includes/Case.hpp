/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** Case.hpp
*/

#pragma once

#include "Object.hpp"

class Case : public Object {
public:
    Case(float x, float y, const std::string& texturePath);
    Case(float x, float y, sf::Texture &texture);
};
