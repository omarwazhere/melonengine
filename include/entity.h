#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "data.h"

class Entity {
    protected:
        std::string name;
        char symbol;
        position pos;
        bool is_solid;
    public:
        Entity(std::string n, int startx, int starty, bool is_solid, char Symbol);

        void getPosition(int &outX, int &outY) const;
        char getSymbol() const;

        virtual void update() {};

        virtual ~Entity() = default;
};

class MovingEntity : public Entity {
    protected:
        velocity velocity;
    public:
        MovingEntity(std::string n, int startx, int starty, float resistance, bool is_solid,
        char Symbol);

        void update() {};

        void move();
};

class Player : public MovingEntity {
    public:
        Player(std::string n, int startx, int starty, float resistance, bool is_solid, char Symbol);

        void update() override;
};

#endif // ENTITY_H