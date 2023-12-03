//
// Created by nathan on 12/2/23.
//

#include "Case.hpp"

Case::Case() : Object()
{
    texture.loadFromFile("./assets/Case.png");
    sprite.setTexture(texture);
}

Case::Case(float x, float y) : Object(x, y)
{
    texture.loadFromFile("./assets/Case.png");
    sprite.setTexture(texture);
}

Case::Case(float x, float y, const std::string& texturePath) : Object(x, y, texturePath) {
    // The texture is already loaded by the Object constructor
}
