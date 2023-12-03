//
// Created by nathan on 12/2/23.
//

#include "Case.hpp"
#include "GridConfig.hpp"

Case::Case(float x, float y, const std::string &texturePath) : Object(x, y, texturePath), type(OTHER) {
}

Case::Case(float x, float y, CaseType type, sf::Texture &texture) : Object(x, y, texture), type(type) {
}

Case::~Case() = default;

void Case::update(sf::Event event, float deltaTime) {
    static bool isPressed = false;
    if (event.mouseButton.x >= x && event.mouseButton.x <= x + GridConfig::SQUARE_SIZE &&
        event.mouseButton.y >= y && event.mouseButton.y <= y + GridConfig::SQUARE_SIZE) {
        if (event.type == sf::Event::MouseButtonPressed) {
            isPressed = true;
        }
        if (event.type == sf::Event::MouseButtonReleased && isPressed) {
            std::cout << *this << std::endl;
            isPressed = false;
        }
    }
}

void Case::draw(sf::RenderWindow &window, Engine *engines) {
    window.draw(this->sprite); // definir couleur item
    if (engines != nullptr) {
        if (sf::Mouse::getPosition(window).x >= x && sf::Mouse::getPosition(window).x <= x + GridConfig::SQUARE_SIZE &&
            sf::Mouse::getPosition(window).y >= y && sf::Mouse::getPosition(window).y <= y + GridConfig::SQUARE_SIZE) {
            if (this->type == CaseType::COPPER || this->type == CaseType::ROCK) {
                if (engines->type == EngineType::DRILL) {
                    engines->setColor(sf::Color::Green);
                } else {
                    engines->setColor(sf::Color::Red);
                }
            } else {
                if (engines->type != EngineType::DRILL) {
                    engines->setColor(sf::Color::Green);
                } else {
                    engines->setColor(sf::Color::Red);
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const Case &aCase) {
    std::map<CaseType, std::string> caseTypeMap = {
            {COPPER, "COPPER"},
            {DIRT,   "DIRT"},
            {ROCK,   "ROCK"},
            {OTHER,  "OTHER"}
    };
    stream << "Case(" << aCase.x << ", " << aCase.y << ", " << caseTypeMap[aCase.type] << ")";
    return stream;
}

void Case::update(sf::Event event, float deltaTime, Engine *&attachedMouse) {
    update(event, deltaTime);
    if (attachedMouse == nullptr) return;
    if (event.mouseButton.x >= x && event.mouseButton.x <= x + GridConfig::SQUARE_SIZE &&
        event.mouseButton.y >= y && event.mouseButton.y <= y + GridConfig::SQUARE_SIZE) {
        if (event.type == sf::Event::MouseButtonReleased) { //faire condition pour poser
            if (this->type == CaseType::COPPER || this->type == CaseType::ROCK) {
                if (attachedMouse->type == EngineType::DRILL)
                    attachedMouse = nullptr;
            } else {
                if (attachedMouse->type != EngineType::DRILL)
                    attachedMouse = nullptr;
            }
        }
    }
}
