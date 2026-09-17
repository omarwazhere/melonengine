#include <cmath>

#include "../include/entity.h"
#include "../include/data.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

/*
Definitions of entities' methods
All prototypes are in include/entity.h
*/

bool checkSolidEntity(position pos);

// Get the position of an entity
void Entity::getPosition(int &outX, int &outY) const {
    outX = std::round(pos.x);
    outY = std::round(pos.y);
}

// Get the symbol of an entity
char Entity::getSymbol() const {
    return symbol;
}

// Check if an entity is solid or not
bool Entity::check_solid() {
    return is_solid;
}

// Move a moving entity
void MovingEntity::move() {
    pos.x += velocity.velx;
    pos.y += velocity.vely;
    if (checkSolidEntity(pos)) {
        // Return to older position
        pos.x -= velocity.velx;
        pos.y -= velocity.vely;

        // Stop when collided
        velocity.velx = 0;
        velocity.vely = 0;
    }

    // Apply resistance after movement so velocity gradually decays.
    velocity.velx *= velocity.resistance;
    velocity.vely *= velocity.resistance;
}

// Update the player's velocity
void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocity.vely -= 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity.vely += 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity.velx += 1.0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.velx -= 1.0;
    }

    if (std::abs(velocity.velx) >= 1.0 || std::abs(velocity.vely) >= 1.0) {
        move();
    }
}

// Check the existance of a solid entity in a position
bool checkSolidEntity(position pos) {
    /*
    int x, y;
    for (auto &entity : g_entities) {
        entity.getPosition(x, y);
        if (x == pos.x && y == pos.y && entity.check_solid()) {
            return true;
        }
    }
    */
    return false;
}