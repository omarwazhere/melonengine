#include <cmath>
#include <vector>

#include "melon/melonlib.h"

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

// Update a mob
void Mob::update() {
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