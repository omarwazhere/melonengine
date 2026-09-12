#include <iostream>
#include <vector>

#include "../include/world.h"

std::vector<std::vector<char>> basicRender(position camera, World *world);
void display(std::vector<std::vector<char>> world);

World::World(unsigned int Size, const unsigned int Render_dist, char Air,
std::vector<Entity> entities)
: size(Size), render_dist(Render_dist), air(Air), entities(entities) {}

unsigned int World::getSize() {
    return size;
}

std::vector<Entity> World::getEntities() {
    return entities;
}

unsigned int World::getRenderDist() {
    return render_dist;
}

char World::getAir() {
    return air;
}

SinglePlayer::SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &Player,
char Air, std::vector<Entity> entities) 
: World(Size, Render_dist, Air, entities), player(Player) {}

void SinglePlayer::render(position camera) {
    std::vector<std::vector<char>> buffer = basicRender(camera, this);
    int playerx, playery;
    char symbol = player.getSymbol();
    player.getPosition(playerx, playery);
    buffer[playerx][playery] = symbol;
    display(buffer);
}

MultiPlayer::MultiPlayer(unsigned int Size, const unsigned int Render_dist, 
    std::vector<Player> &Players, char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), players(Players) {}

std::vector<std::vector<char>> basicRender(position camera, World *world) {
    // UNFINISHED
    unsigned int size = world->getSize();
    unsigned int render_dist = world->getRenderDist();
    char air = world->getAir();
    std::vector entities = world->getEntities();
    const unsigned int tiles = render_dist * render_dist;
    std::vector<std::vector<char>> buffer(tiles, std::vector<char>(tiles, air));

    int screenX, screenY, posX, posY;
    char symbol;
    for (Entity &current : entities) {
        current.getPosition(posX, posY);
        screenX =  posX - (camera.x - render_dist);
        screenY =  posY - (camera.y - render_dist);

        if (screenX >= 0 && screenY < size && screenX >= 0 && screenX < size) {
            symbol = current.getSymbol();
            buffer[screenX][screenY] = symbol;
        }
    }

    return buffer;
}

void display(std::vector<std::vector<char>> world) {
    for (const auto &line : world) {
        for (char currentSymbol : line) {
            std::cout << currentSymbol;
        }
        std::cout << '\n';
    }
}