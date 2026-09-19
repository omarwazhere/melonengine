#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "types.h"

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
        bool is_solid; 
    public:
        const unsigned int id;
        Entity(entityInfo info);

        void getPosition(int &outX, int &outY) const;
        char getSymbol() const;
        bool check_solid() const;

        virtual void update() {};

        virtual ~Entity() = default;
};

// Moving entity child class
class MovingEntity : public Entity {
    public:
        velocity velocity;
        MovingEntity(entityInfo info);

        void move();
};

#endif // ENTITY_H