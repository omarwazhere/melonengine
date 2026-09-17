#include <string>
#include <vector>

#include "../include/types.h"
#include "../include/entity.h"
#include "../include/world.h"

// Constructor methods for worlds and entities

// Entity constructors

// Base entity constuctor
Entity::Entity(entityInfo info) : name(info.n), is_solid(info.is_solid), symbol(info.symbol) {
    pos.x = info.startx;
    pos.y = info.starty;
}

// Moving entity constructor
MovingEntity::MovingEntity(entityInfo info, float resistance) : Entity(info) {
    velocity.resistance = resistance;
    velocity.velx = 0.0; velocity.vely = 0.0;
}

// Player constructor
Player::Player(entityInfo info, float resistance) : MovingEntity(info, resistance) {}


// World constructors

// Base world constructor
World::World(worldInfo info) : size(info.size), render_dist(info.render_dist), air(info.air) {}

// Singleplayer world constructor
SinglePlayer::SinglePlayer(worldInfo info, Player &Player) : World(info), player(&Player) {}