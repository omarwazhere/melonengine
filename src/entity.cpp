#include <cmath>
#include <vector>

#include "melon/melonlib.hpp"

/*
Definitions of entities' methods
All prototypes are in include/entity.h
*/

// Get the position of an entity
void Entity::getPosition(int &outX, int &outY) const {
    outX = pos.x;
    outY = pos.y;
}

// Get the symbol of an entity
char Entity::getSymbol() const {
    return symbol;
}

// Check if an entity is solid or not
bool Entity::check_solid() const {
    return is_solid;
}

// Check if entity is collided
bool Entity::collided() {
    if (is_solid) return false;
    unsigned int size = world->getSize();
    return checkSolidEntity(pos, this->id) || pos.x > size || pos.y > size;
}

// Move a moving entity
void MovingEntity::move() {
    int prevX = pos.x;
    int prevY = pos.y;
    pos.x += static_cast<int>(std::round(velocity.velx));
    pos.y += static_cast<int>(std::round(velocity.vely));

    if (collided()) {
        pos.x = prevX;
        pos.y = prevY;
        velocity.velx = 0;
        velocity.vely = 0;
    }
}

// Move a mob
void Mob::move() {
    int prevX = pos.x;
    int prevY = pos.y;

    velocity.velx = xdir;
    velocity.vely = ydir;

    pos.x += static_cast<int>(std::round(velocity.velx));
    pos.y += static_cast<int>(std::round(velocity.vely));

    if (collided()) {
        pos.x = prevX;
        pos.y = prevY;

        if (velocity.velx != 0) {
            xdir *= -1;
            velocity.velx = xdir;
        }
        if (velocity.vely != 0) {
            ydir *= -1;
            velocity.vely = ydir;
        }
    }
}

// Move a mob without bouncing at collision
void Mob::blind_move() {
    int prevX = pos.x;
    int prevY = pos.y;

    velocity.velx = xdir;
    velocity.vely = ydir;

    pos.x += static_cast<int>(std::round(velocity.velx));
    pos.y += static_cast<int>(std::round(velocity.vely));

    if (collided()) {
        pos.x = prevX;
        pos.y = prevY;
    }
}

// Make a mob follow a position
void Mob::follow(int targetx, int targety, unsigned int dist) {
    if (targetx + dist > pos.x) xdir = 1;
    else if (targetx - dist < pos.x) xdir = -1;

    if (targety + dist > pos.y) ydir = 1;
    else if (targety - dist < pos.y) ydir = -1;

    blind_move();
}

// Make a mob wander around
void Mob::wander() {
    if (wanderSteps == 0) {
        xdir = (std::rand() % 3) - 1;
        ydir = (std::rand() % 3) - 1;
        wanderSteps = std::rand() % 10 + 5;
    } else {
        move();
        wanderSteps--;
    }
}