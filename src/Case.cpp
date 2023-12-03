//
// Created by nathan on 12/2/23.
//

#include "Case.hpp"

Case::Case(float x, float y, const std::string& texturePath) : Object(x, y, texturePath) {
    std::cout << "Case constructor with " << texturePath << " x= " << x << " y= " << y << std::endl;
}

Case::Case(float x, float y, sf::Texture &texture) : Object(x, y, texture) {
    std::cout << "Case constructor with texture x= " << x << " y= " << y << std::endl;
}
