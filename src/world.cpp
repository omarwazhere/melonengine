#include <vector>
#include "../include/world.h"

World::World(unsigned int Size, const unsigned int Render_dist, char Air)
: size(Size), render_dist(Render_dist), air(Air) {}

SinglePlayer::SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &Player,
char Air) 
: World(Size, Render_dist, Air), player(Player) {}

MultiPlayer::MultiPlayer(unsigned int Size, const unsigned int Render_dist, 
    std::vector<Player> &Players, char Air)
: World(Size, Render_dist, Air), players(Players) {}

void World::render(position camera) {
    // UNFINISHED
    const unsigned int tiles = render_dist * render_dist;
    char* buffer = new char[tiles];

    

    std::vector<char> screenBuffer(' ', tiles);
}