#include <string>
#include <vector>

#include "melon/melonlib.h"

// Constructor methods for worlds and entities

// Base entity constuctor
Entity::Entity(entityInfo info) : name(info.n), is_solid(info.is_solid), symbol(info.symbol), id(info.id) {
    pos.x = info.startx;
    pos.y = info.starty;
}

// Moving entity constructor
MovingEntity::MovingEntity(entityInfo info) : Entity(info) {
    velocity.velx = 0.0; velocity.vely = 0.0;
}

// Object constructor
Object::Object(entityInfo info) : Entity(info) {}

// Base world constructor
World::World(worldInfo info) : size(info.size), render_dist(info.render_dist), air(info.air) {}