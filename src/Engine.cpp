//
// Created by nathan on 12/3/23.
//

#include "../includes/Engine.hpp"

Engine::Engine(float x, float y, EngineType type, sf::Texture &texture) : Object(x, y, texture), type(type) {


}

Engine::~Engine() = default;

void Engine::update(sf::Event event, float deltaTime) {
    Object::update(event, deltaTime);
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
