#include <cmath>

#include "../include/entity.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

/*
Definitions of entities' methods
All prototypes are in include/entity.h
*/

// Get the position of an entity
void Entity::getPosition(int &outX, int &outY) const {
    outX = std::round(pos.x);
    outY = std::round(pos.y);
}

// Get the symbol of an entity
char Entity::getSymbol() const {
    return symbol;
}

// Move a moving entity
void MovingEntity::move() {
    pos.x += velocity.velx;
    pos.y += velocity.vely;

    // Apply resistance after movement so velocity gradually decays.
    velocity.velx *= velocity.resistance;
    velocity.vely *= velocity.resistance;
}

// Update the player's velocity
void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocity.vely += 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity.vely -= 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity.velx += 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.velx -= 1.0;
    }

    move();
}