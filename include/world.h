#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "data.h"
#include "entity.h"

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

class SinglePlayer : public World {
    private:
        Player player;
    public:
        SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &Player, 
        char Air, std::vector<Entity> entities);

        void render(position camera) override;
};

class MultiPlayer : public World {
    private:
        std::vector<Player> players;
    public:
        MultiPlayer(unsigned int Size, const unsigned int Render_dist, std::vector<Player> &Players,
        char Air, std::vector<Entity> entities);
};

#endif