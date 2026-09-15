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
        World(unsigned int Size, unsigned int Render_dist, char Air, 
        std::vector<Entity> entites);

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
        char Air, std::vector<Entity> entities);

        void render(position camera) override;
};

// An abstract (supposed to be concrete but is unfinished) child multiplayer world
class MultiPlayer : public World {
    /*
    TODO: Override and implement render() virtual method to make the
    multiplayer world class concrete and ready
    */
    private:
        std::vector<Player> players;
    public:
        MultiPlayer(unsigned int Size, const unsigned int Render_dist, std::vector<Player> &Players,
        char Air, std::vector<Entity> entities);

};

#endif