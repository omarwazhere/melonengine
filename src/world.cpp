#include <iostream>
#include <vector>

#include "../include/world.h"

/*
Definitions of worlds' methods
All prototypes are in include/world.h
*/

std::vector<std::vector<char>> basicRender(position camera, World *world);
void display(std::vector<std::vector<char> > world);

// Get the size of a world
unsigned int World::getSize() {
    return size;
}

// Get the entities in a world
std::vector<Entity> World::getEntities() {
    return entities;
}

// Get the render distance of a world
unsigned int World::getRenderDist() {
    return render_dist;
}

// Get the air symbol of a world
char World::getAir() {
    return air;
}

// Render a single player world
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

// Render all normal entities in a world template
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

// Print out a world within a render distance
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