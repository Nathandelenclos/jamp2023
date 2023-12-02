//
// Created by nathan on 12/2/23.
//

#include "Case.hpp"

Case::Case() : Object()
{
    texture.loadFromFile("../assets/Case.png");
    sprite.setTexture(texture);
}

Case::Case(float x, float y) : Object(x, y)
{
    texture.loadFromFile("../assets/Case.png");
    sprite.setTexture(texture);
}
