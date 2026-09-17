#include <string>
#include <vector>

#include "../include/data.h"
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
World::World(unsigned int Size, const unsigned int Render_dist, char Air)
: size(Size), render_dist(Render_dist), air(Air) {}

// Singleplayer world constructor
SinglePlayer::SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &Player,
char Air)
: World(Size, Render_dist, Air), player(&Player) {}