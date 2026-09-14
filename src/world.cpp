#include <iostream>
#include <vector>

#include "../include/world.h"

std::vector<std::vector<char>> basicRender(position camera, World *world);
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
    std::vector<std::vector<char>> buffer = basicRender(camera, this);
    int playerx, playery;
    char symbol = player->getSymbol();
    player->getPosition(playerx, playery);

    int screenX = playerx - (camera.x - static_cast<int>(getRenderDist()));
    int screenY = playery - (camera.y - static_cast<int>(getRenderDist()));
    if (screenY >= 0 && static_cast<size_t>(screenY) < buffer.size()
        && screenX >= 0 && static_cast<size_t>(screenX) < buffer[screenY].size()) {
        buffer[buffer.size() - screenY][screenX] = symbol;
    }
    display(buffer);
}

MultiPlayer::MultiPlayer(unsigned int Size, const unsigned int Render_dist, 
    std::vector<Player> &Players, char Air, std::vector<Entity> entities)
: World(Size, Render_dist, Air, entities), players(Players) {}

std::vector<std::vector<char>> basicRender(position camera, World *world) {
    if (!world) return {};

    unsigned int render_dist = world->getRenderDist();
    char air = world->getAir();
    
    const size_t tiles = static_cast<size_t>(render_dist) * 2 + 1;
    std::vector<std::vector<char>> buffer(tiles, std::vector<char>(tiles, air));

    int posX{}, posY{};
    std::vector<Entity> entities = world->getEntities();

    for (auto& current : entities) {
        current.getPosition(posX, posY);

        int screenX = posX - (camera.x - static_cast<int>(render_dist));
        int screenY = posY - (camera.y - static_cast<int>(render_dist));

        // Strict boundary check before indexing outer vector (row) and inner vector (col)
        if (screenY >= 0 && static_cast<size_t>(screenY) < buffer.size()) {
            if (screenX >= 0 && static_cast<size_t>(screenX) < buffer[screenY].size()) {
                buffer[buffer.size() - screenY][screenX] = current.getSymbol();
            }
        }
    }

    return buffer;
}

void display(std::vector<std::vector<char>> world) {
    std::vector<char> line;
    char currentSymbol;
    for (size_t i = 0; i < world.size(); ++i) {
        line = world[i];
        for (size_t j = 0; j < line.size(); ++j) {
            currentSymbol = line[j];
            std::cout << currentSymbol;
        }
        line.clear();
        std::cout << '\n';
    }
}