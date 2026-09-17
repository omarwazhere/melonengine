#include <cmath>
#include <vector>

#include "../include/entity.h"
#include "../include/types.h"
#include "../include/helpers.h"

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
    position nextPosition{
        static_cast<int>(std::round(pos.x + velocity.velx)),
        static_cast<int>(std::round(pos.y + velocity.vely))
    };

    if (isPositionInWorld(nextPosition) && !checkSolidEntity(nextPosition)) {
        pos.x += velocity.velx;
        pos.y += velocity.vely;
    } else {
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
    std::vector<Entity> entities;
    int x, y;
    for (Entity &entity : entities) {
        entity.getPosition(x, y);
        if (x == pos.x && y == pos.y) {
            return true;
        }
    }
    return false;
}