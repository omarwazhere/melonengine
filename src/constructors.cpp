#include <string>
#include <vector>

#include "../include/data.h"
#include "../include/entity.h"
#include "../include/world.h"

// Constructor methods for worlds and entities

// Entity constructors
Entity::Entity(std::string n, int startx, int starty, bool is_solid,
char Symbol) 
: name(n), is_solid(is_solid), symbol(Symbol) {
    pos.x = startx;
    pos.y = starty;
}

MovingEntity::MovingEntity(std::string n, int startx, int starty, float resistance, bool is_solid,
char Symbol)
: Entity(n, startx, starty, is_solid, Symbol) {
    velocity.resistance = resistance;
    velocity.velx = 0.0; velocity.vely = 0.0;
}

Player::Player(std::string n, int startx, int starty, float resistance, bool is_solid,
char Symbol)
: MovingEntity(n, startx, starty, resistance, is_solid, Symbol) {}


// World constructors
World::World(unsigned int Size, const unsigned int Render_dist, char Air,
std::vector<Entity> entities)
: size(Size), render_dist(Render_dist), air(Air), entities(entities) {}

SinglePlayer::SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &playerRef,
char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), player(&playerRef) {}

MultiPlayer::MultiPlayer(unsigned int Size, const unsigned int Render_dist, 
    std::vector<Player> &Players, char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), players(Players) {}