#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "types.h"
#include "entity.h"

/*
This is the worlds' header file

All constructor definitons are in src/constructors.cpp
All other methods of any type of world is in src/world.cpp
*/

// Base world class
class World {
    protected:
        unsigned int size;
        unsigned int render_dist;
        char air;
        std::vector<Entity> entities;
    public:
        World(worldInfo info);

        virtual ~World() = default;

        unsigned int getRenderDist();
        unsigned int getSize();
        char getAir();
        std::vector<Entity> getEntities();

        void newEntity(Entity &entity);

        virtual void render(position camera) {};
};

// A concrete child singleplayer world
class SinglePlayer : public World {
    private:
        Player *player;
    public:
        SinglePlayer(worldInfo info, Player &Player);

        void render(position camera);
};
extern SinglePlayer *world;

#endif