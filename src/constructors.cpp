#include <string>
#include <vector>

#include "../include/data.h"
#include "../include/entity.h"
#include "../include/world.h"
#include "../include/globals.h"

// Constructor methods for worlds and entities

// Entity constructors
// Base entity constuctor
Entity::Entity(std::string n, int startx, int starty, bool is_solid,
char Symbol) 
: name(n), is_solid(is_solid), symbol(Symbol) {
    pos.x = startx;
    pos.y = starty;
}

// Moving entity constructor
MovingEntity::MovingEntity(std::string n, int startx, int starty, float resistance, bool is_solid,
char Symbol)
: Entity(n, startx, starty, is_solid, Symbol) {
    velocity.resistance = resistance;
    velocity.velx = 0.0; velocity.vely = 0.0;
}

// Player constructor
Player::Player(std::string n, int startx, int starty, float resistance, bool is_solid,
char Symbol)
: MovingEntity(n, startx, starty, resistance, is_solid, Symbol) {}


// World constructors
// Base world constructor
World::World(unsigned int Size, const unsigned int Render_dist, char Air,
std::vector<Entity> entities)
: size(Size), render_dist(Render_dist), air(Air), entities(entities) {
    g_entities = entities;
}

// Singleplayer world constructor
SinglePlayer::SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &playerRef,
char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), player(&playerRef) {}

// Multiplayer world constructo
MultiPlayer::MultiPlayer(unsigned int Size, const unsigned int Render_dist, 
    std::vector<Player> &Players, char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), players(Players) {}