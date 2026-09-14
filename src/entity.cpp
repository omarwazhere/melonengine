#include "..\include\entity.h"
#include <SFML/Graphics.hpp>

Entity::Entity(std::string n, int startx, int starty, bool is_solid,
char Symbol) 
: name(n), is_solid(is_solid), symbol(Symbol) {
    pos.x = startx;
    pos.y = starty;
}

void Entity::getPosition(int &outX, int &outY) const {
    outX = pos.x;
    outY = pos.y;
}

char Entity::getSymbol() const {
    return symbol;
}

void MovingEntity::move() {
    pos.x += velocity.velx;
    pos.y += velocity.vely;
    velocity.velx = 0; // For testing, resistance physics later
    velocity.vely = 0; // too
}

MovingEntity::MovingEntity(std::string n, int startx, int starty, float resistance, bool is_solid,
char Symbol)
: Entity(n, startx, starty, is_solid, Symbol) {
    velocity.resistance = resistance;
    velocity.velx = 0.0; velocity.vely = 0.0;
}

Player::Player(std::string n, int startx, int starty, float resistance, bool is_solid,
char Symbol)
: MovingEntity(n, startx, starty, resistance, is_solid, Symbol) {}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocity.vely += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity.vely -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity.velx += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.velx -= 1;
    }

    // velocity.velx *= velocity.resistance; Commented for testing
    move();
}