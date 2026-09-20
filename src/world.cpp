#include <iostream>
#include <vector>
#include <string>

#include "melon/melonlib.hpp"

std::string getWorld(std::vector<std::vector<char>> map);

/*
Definitions of worlds' methods
All prototypes are in include/world.h
*/

void display(std::vector<std::vector<char>> world);

World::~World() {
    for (Entity* entity : entities) {
        delete entity;
    }
}

// Get the size of a world
unsigned int World::getSize() {
    return size;
}

// Get the entities in a world
std::vector<Entity*> World::getEntities() {
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

// Add a new moving entity
void World::newMovingEntity(MovingEntity &entity) {
    entities.push_back(&entity);
}

// Add a new object
void World::newObject(Object &entity) {
    entities.push_back(&entity);
}

// Render all normal entities in a world template
void World::render(position camera) {
    if (!this) return;
    
    const size_t tiles = static_cast<size_t>(render_dist) * 2 + 1;
    std::vector<std::vector<char>> buffer(tiles, std::vector<char>(tiles, air));

    int posX{}, posY{};

    for (auto& current : entities) {
        current->getPosition(posX, posY);

        int screenX = posX - (camera.x - static_cast<int>(render_dist));
        int screenY = posY - (camera.y - static_cast<int>(render_dist));

        // Strict boundary check before indexing outer vector (row) and inner vector (col)
        if (screenY >= 0 && static_cast<size_t>(screenY) < buffer.size()) {
            if (screenX >= 0 && static_cast<size_t>(screenX) < buffer[screenY].size()) {
                buffer[screenY][screenX] = current->getSymbol();
            }
        }
    }
    display(buffer);
}

// Print out a world within a render distance
void display(std::vector<std::vector<char>> world) {
    std::string str = getWorld(world);
    std::cout << str << "\x1b[H" << std::flush;
}

// Covert world map to one string
std::string getWorld(std::vector<std::vector<char>> map) {
    std::string str;
    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            str += map[i][j];
        }
        str += '\n';
    }
    return str;
}