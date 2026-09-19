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

// Move a moving entity
void MovingEntity::move() {
    int prevX = pos.x;
    int prevY = pos.y;
    unsigned int size = world->getSize();
    pos.x += static_cast<int>(std::round(velocity.velx));
    pos.y += static_cast<int>(std::round(velocity.vely));

    if (checkSolidEntity(pos, this->id) || pos.x > size || pos.y > size) {
        pos.x = prevX;
        pos.y = prevY;
        velocity.velx = 0;
        velocity.vely = 0;
    }
}