#include <chrono>
#include <iostream>
#include <thread>
#include <windows.h>

#include "melon/melonlib.h"

World* world = nullptr;
unsigned int current_id = 0;

// This is a TEST FILE

int main() {
    setup();
    setWorld(100);

    entityInfo someone = {entityInfo{"someone?", 0, 9, true, '*', 0}};
    summonObject(someone);

    MovingEntity *hero = new MovingEntity(entityInfo{"omarwazhere", 0, 0, true, '^', ++current_id});
    world->newMovingEntity(*hero);

    int x, y;
    hero->getPosition(x, y);
    while (true) {
        
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        if (GetAsyncKeyState('W') & 0x8000) {
            hero->velocity.vely -= 1.0;
        }
        if (GetAsyncKeyState('A') & 0x8000) {
            hero->velocity.velx -= 1.0;
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            hero->velocity.vely += 1.0;
        }

        if (GetAsyncKeyState('D') & 0x8000) {
            hero->velocity.velx += 1.0;
        }

        hero->move();
        hero->getPosition(x, y);

        hero->velocity.velx = 0;
        hero->velocity.vely = 0;

        tick(50, x, y);
    }

    delete world;
    return 0;
}