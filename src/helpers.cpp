#include <windows.h>
#include <chrono>
#include <thread>
#include <iostream>

#include "../include/types.h"
#include "../include/world.h"
#include "../include/entity.h"

// Turn ANSI escape codes on
void setup() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

// Set the world
void setWorld(int size) {
    const unsigned int worldSize = size > 0 ? static_cast<unsigned int>(size) : 0;

    delete world;
    world = new World(worldInfo{worldSize, 10, ' '});
}

// Check if a position is in the world
bool isPositionInWorld(position pos) {
    const unsigned int worldSize = world->getSize();
    return pos.x >= 0 && pos.y >= 0
        && static_cast<unsigned int>(pos.x) < worldSize
        && static_cast<unsigned int>(pos.y) < worldSize;
}

// Tick the game
void tick(int millisecs, int renderx, int rendery) {
    world->render(position{renderx, rendery});
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecs));
}

// Summon a moving entity
void summonMovingEntity(entityInfo &info) {
    current_id++;
    info.id = current_id;
    MovingEntity *newEntity = new MovingEntity(info);
    world->newMovingEntity(*newEntity);
}

// Check the existance of a solid entity in a position
bool checkSolidEntity(position pos, unsigned int id) {
    int x, y;
    for (auto &entity : world->entities) {
        entity->getPosition(x, y);
        if (x == pos.x && y == pos.y && entity->check_solid() && entity->id != id) {
            return true;
        }
    }
    return false;
}