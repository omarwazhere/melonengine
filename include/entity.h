#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "types.h"

#include <string>

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
        Entity(entityInfo info);

        void getPosition(int &outX, int &outY) const;
        char getSymbol() const;
        bool check_solid();

        virtual void update() {};

        virtual ~Entity() = default;
};

// Moving entity child class
class MovingEntity : public Entity {
    protected:
        velocity velocity;
    public:
        MovingEntity(entityInfo info, float resistance);

        void update() {};

        void move();
};

// Player grandchild class
class Player : public MovingEntity {
    public:
        Player(entityInfo info, float resistance);

        // Update is overriden for key controls
        void update() override;
};

#endif // ENTITY_H