#include <chrono>
#include <iostream>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#endif

#include "melon/melonlib.h"

// Set up the console
void setup() {
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
    #endif

    std::cout << "\e[?25l" << std::flush;
}

// Set the world
void setWorld(unsigned int size, unsigned int render_dist) {
    delete world;
    world = new World(worldInfo{size, render_dist, ' '});
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

// Summon an object entity
void summonObject(entityInfo &info) {
    current_id++;
    info.id = current_id;
    Object *newEntity = new Object(info);
    world->newObject(*newEntity);
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