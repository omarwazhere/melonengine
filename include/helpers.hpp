#pragma once

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "types.hpp"
#include "entity.hpp"

// This is the header file for helper functions

void setup();
void setWorld(unsigned int size, unsigned int render_dist);
void tick(int millisecs, int renderx, int rendery);
bool isPositionInWorld(position pos);
void summonMovingEntity(entityInfo &info);
void summonObject(entityInfo &info);
bool checkSolidEntity(position pos, unsigned int id);

#endif // DATA_HPP