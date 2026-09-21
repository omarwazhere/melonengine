#include <chrono>
#include <iostream>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#endif

#include "../src/melon/melonlib.hpp"

World* world = nullptr;
unsigned int current_id = 0;

// This is a TEST FILE

int main() {
    setup();
    setWorld(100, 20);

    Mob *dog = new Mob(entityInfo{"dog no.432149", 5, 0, true, 'O', ++current_id});
    world->newMovingEntity(*dog);

    MovingEntity *hero = new MovingEntity(entityInfo{"omarwazhere", 0, 0, true, '^', ++current_id});
    world->newMovingEntity(*hero);

    int x, y;
    bool tamed = false;
    while (true) {
        #ifdef _WIN32
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        if (GetAsyncKeyState(' ') & 0x8000) {
            tamed = true;
        }

        if (GetAsyncKeyState('W') & 0x8000) {
            hero->velocity.vely -= 2.0;
        }
        if (GetAsyncKeyState('A') & 0x8000) {
            hero->velocity.velx -= 2.0;
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            hero->velocity.vely += 2.0;
        }

        if (GetAsyncKeyState('D') & 0x8000) {
            hero->velocity.velx += 2.0;
        }
        #endif

        hero->move();
        hero->getPosition(x, y);

        if (tamed) {
            dog->follow(x, y, 4);
        } else {
            dog->wander();
        }

        hero->velocity.velx = 0;
        hero->velocity.vely = 0;

        tick(50, x, y);
    }

    delete world;
    return 0;
}