//
// Created by nathan on 12/3/23.
//

#include "Engine.hpp"

Engine::Engine(float x, float y, EngineType type, sf::Texture &texture) : Object(x, y, texture), type(type) {


}


Engine::~Engine() = default;

void Engine::update(sf::Event event, float deltaTime, Engine *attachedEngine,  Engine *&linkStart, Engine *&linkEnd) {
    Object::update(event, deltaTime);
    if (attachedEngine != nullptr) return;
    sf::Rect<float> bounds = sprite.getGlobalBounds();
    static bool isPressed = false;
    if (event.mouseButton.x >= bounds.left && event.mouseButton.x <= bounds.left + bounds.width &&
        event.mouseButton.y >= bounds.top && event.mouseButton.y <= bounds.top + bounds.height) {
        if (event.type == sf::Event::MouseButtonPressed) {
            isPressed = true;
        }
        if (event.type == sf::Event::MouseButtonReleased && isPressed) {
            if (linkStart == nullptr) {
                linkStart = this;
                std::cout << "linkStart: " << *linkStart << std::endl;
            } else if (linkEnd == nullptr) {
                linkEnd = this;
                std::cout << "linkEnd: " << *linkEnd << std::endl;
            }
            isPressed = false;
        }
    }
}

void Engine::setColor(sf::Color color) {
    this->sprite.setColor(color);
}

std::ostream &operator<<(std::ostream &ostream, const Engine &e) {
    std::map<EngineType, std::string> engineTypeMap = {
            {DRILL,    "DRILL"},
            {FORGE,    "FORGE"},
            {INDUSTRY, "INDUSTRY"}
    };
    ostream << "Engine(" << e.x << ", " << e.y << ", " << engineTypeMap[e.type] << ")";
    return ostream;
}
