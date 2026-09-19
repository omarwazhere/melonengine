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

// World class
class World {
    protected:
        unsigned int size;
        unsigned int render_dist;
        char air;
    public:
        std::vector<Entity*> entities;
        World(worldInfo info);

        virtual ~World();

        unsigned int getRenderDist();
        unsigned int getSize();
        char getAir();
        std::vector<Entity*> getEntities();

        void newMovingEntity(MovingEntity &entity);
        void render(position camera);
};

extern World *world;
extern unsigned int current_id;

#endif