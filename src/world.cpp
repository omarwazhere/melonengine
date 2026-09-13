#include <iostream>
#include <vector>

#include "../include/world.h"

std::vector<std::vector<char> > basicRender(position camera, World *world);
void display(std::vector<std::vector<char> > world);

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

SinglePlayer::SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &playerRef,
char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), player(&playerRef) {}

void SinglePlayer::render(position camera) {
    std::vector<std::vector<char> > buffer = basicRender(camera, this);
    int playerx, playery;
    char symbol = player->getSymbol();
    player->getPosition(playerx, playery);
    buffer[playery][playerx] = symbol;
    display(buffer);
}

MultiPlayer::MultiPlayer(unsigned int Size, const unsigned int Render_dist, 
    std::vector<Player> &Players, char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), players(Players) {}

std::vector<std::vector<char> > basicRender(position camera, World *world) {
    unsigned int render_dist = world->getRenderDist();
    char air = world->getAir();
    std::vector<Entity> entities = world->getEntities();
    const unsigned int tiles = render_dist * 2;
    std::vector<std::vector<char> > buffer(tiles, std::vector<char>(tiles, air));

    int screenX, screenY, posX, posY;
    char symbol;
    for (size_t i = 0; i < entities.size(); ++i) {
        Entity &current = entities[i];
        current.getPosition(posX, posY);
        screenX = posX - (camera.x - static_cast<int>(render_dist));
        screenY = posY - (camera.y - static_cast<int>(render_dist));

        if (screenX >= 0 && screenY >= 0 &&
            screenX < static_cast<int>(tiles) &&
            screenY < static_cast<int>(tiles)) {
            symbol = current.getSymbol();
            buffer[screenY][screenX] = symbol;
        }
    }

    return buffer;
}

void display(std::vector<std::vector<char> > world) {
    std::vector<char> line;
    char currentSymbol;
    for (size_t i = 0; i < world.size(); ++i) {
        line = world[i];
        for (size_t j = 0; j < line.size(); ++j) {
            currentSymbol = line[j];
            std::cout << currentSymbol;
        }
        std::cout << '\n';
    }
}