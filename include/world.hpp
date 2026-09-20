#pragma once

#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "types.hpp"
#include "entity.hpp"

/*
This is the worlds' header file

All constructors are in src/constructors.cpp
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
        void newObject(Object &entity);

        void render(position camera);
};

#endif // WORLD_HPP