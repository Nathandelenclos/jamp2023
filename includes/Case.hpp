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
    Case();
    Case(float x, float y);
    Case(float x, float y, const std::string& texturePath);
};
