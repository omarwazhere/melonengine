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
void setWorld(int size, Player &player) {
    const unsigned int worldSize = size > 0 ? static_cast<unsigned int>(size) : 0;

    delete world;
    world = new SinglePlayer(worldInfo{worldSize, 10, ' '}, player);
}

// Check if a position is in the world
bool isPositionInWorld(position pos) {
    const unsigned int worldSize = world->getSize();
    return pos.x >= 0 && pos.y >= 0
        && static_cast<unsigned int>(pos.x) < worldSize
        && static_cast<unsigned int>(pos.y) < worldSize;
}

// Tick the game
void tick(int millisecs, Player &player) {
    position playerpos{};
    player.update();
    player.getPosition(playerpos.x, playerpos.y);

    std::cout << "X: " << playerpos.x << '\n'; // TEST
    std::cout << "Y: " << playerpos.y << "\n\n"; // TEST

    world->render(playerpos);
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecs));
}

