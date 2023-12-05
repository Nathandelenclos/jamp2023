//
// Created by nathan on 12/3/23.
//

#include "../includes/Link.hpp"

Link::Link(Engine *engine1, Engine *engine2) : engine1(engine1), engine2(engine2), time(0) {
    this->pointA = engine1->getPosition();
    this->pointB = engine2->getPosition();
    this->line = sf::VertexArray(sf::Lines, 2);
    this->line[0].position = this->pointA;
    this->line[1].position = this->pointB;
    this->line[0].color = sf::Color::White;
    this->line[1].color = sf::Color::White;
}

Link::~Link() {

}

void Link::draw(sf::RenderWindow &window) {
    this->pointA = engine1->getPosition();
    this->pointB = engine2->getPosition();
    this->line[0].position = this->pointA;
    this->line[1].position = this->pointB;
    window.draw(this->line);
}

std::ostream &operator<<(std::ostream &ostream, const Link &link) {
    return ostream << "Link(" << link.engine1 << ", " << link.engine2 << ")";
}

Link::Link(const Link &obj) {
    this->engine1 = obj.engine1;
    this->engine2 = obj.engine2;
    this->pointA = obj.pointA;
    this->pointB = obj.pointB;
    this->line = obj.line;
}

void Link::update(int *&money, int moneyObjective) {
    int elapsedTime = clock.getElapsedTime().asMilliseconds();
    std::cout << "elapsedTime: " << elapsedTime << std::endl;
    std::cout << "time: " << time << std::endl;
    if (elapsedTime >= 1000) {
        std::cout << "test" << std::endl;
        if (this->engine1->type == EngineType::DRILL && this->engine2->type == EngineType::FORGE) {
            *money += 5;
        } else if (this->engine1->type == EngineType::FORGE && this->engine2->type == EngineType::INDUSTRY) {
            *money += 10;
        }
        std::cout << "Money: " << *money << std::endl;
        if (*money >= moneyObjective) {
            std::cout << "You win !" << std::endl;
            exit(0);
        }
        clock.restart();
    }
}
