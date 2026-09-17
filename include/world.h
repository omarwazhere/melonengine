#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "data.h"
#include "entity.h"

/*
This is the worlds' header file

All constructor definitons are in src/constructors.cpp
All other methods of any type of world is in src/world.cpp
*/

// An abstract base world class
class World {
    protected:
        unsigned int size;
        unsigned int render_dist;
        char air;
        std::vector<Entity> entities;
    public:
        World(unsigned int Size, unsigned int Render_dist, char Air);

        virtual ~World() = default;
        unsigned int getRenderDist();
        unsigned int getSize();
        char getAir();
        std::vector<Entity> getEntities();

        virtual void render(position camera) = 0;
};

// A concrete child singleplayer world
class SinglePlayer : public World {
    private:
        Player *player;
    public:
        SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &Player,
        char Air);

        void render(position camera) override;
};

#endif