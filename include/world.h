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
    public:
        World(unsigned int Size, unsigned int Render_dist, char Air);

        virtual ~World() = default;

        void render(position camera); // TODO: display world
};

class SinglePlayer : public World {
    private:
        Player player;
    public:
        SinglePlayer(unsigned int Size, const unsigned int Render_dist, Player &Player, char Air);
};

class MultiPlayer : public World {
    private:
        std::vector<Player> players;
    public:
        MultiPlayer(unsigned int Size, const unsigned int Render_dist, std::vector<Player> &Players
        , char Air);
};

#endif