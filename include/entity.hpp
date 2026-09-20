#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

#include "types.hpp"

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

        virtual ~Entity() = default;
};

// Derived moving entity class
class MovingEntity : public Entity {
    public:
        velocity velocity;
        MovingEntity(entityInfo info);

        virtual void move();
};

// Derived (from MovingEntity) mob class
class Mob : public MovingEntity {
    private:
        unsigned int wanderSteps = 0;
    public:
        short int xdir = 0; // TEST
        short int ydir = 1; // TEST
        
        Mob(entityInfo info);

        void wander();
        void follow(int targetx, int targety, unsigned int dist);
        void move() override;
        void blind_move();
};

// Derived static object class
class Object : public Entity {
    public:
        Object(entityInfo info);
};

#endif // ENTITY_HPP