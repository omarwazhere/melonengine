#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "types.h"

/*
This is the entities' header file

All constructors are in src/constructors.cpp
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
        bool collided();

        virtual void update() {}

        virtual ~Entity() = default;
};

// Derived moving entity class
class MovingEntity : public Entity {
    public:
        velocity velocity;
        MovingEntity(entityInfo info);

        void move();
};

// Derived (from MovingEntity) mob class
class Mob : public MovingEntity {
    public:
        short int xdir = 0; // TEST
        short int ydir = 1; // TEST
        
        Mob(entityInfo info);

        void update() override;
};

// Derived static object class
class Object : public Entity {
    public:
        Object(entityInfo info);
};

#endif // ENTITY_H