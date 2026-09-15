#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "data.h"

/*
This is the entities' header file

All constructor definitons are in src/constructors.cpp
All other methods of any entity is in src/entity.cpp
*/

// Entity base class
class Entity {
    protected:
        std::string name;
        char symbol;
        position pos;
        bool is_solid; // TODO: add collision detection for solid entities 
    public:
        Entity(std::string n, int startx, int starty, bool is_solid, char Symbol);

        void getPosition(int &outX, int &outY) const;
        char getSymbol() const;

        virtual void update() {};

        virtual ~Entity() = default;
};

// Moving entity child class
class MovingEntity : public Entity {
    protected:
        velocity velocity;
    public:
        MovingEntity(std::string n, int startx, int starty, float resistance, bool is_solid,
        char Symbol);

        void update() {};

        void move();
};

// Player grandchild class
class Player : public MovingEntity {
    public:
        Player(std::string n, int startx, int starty, float resistance, bool is_solid, char Symbol);

        // Update is overriden for key controls
        void update() override;
};

#endif // ENTITY_H