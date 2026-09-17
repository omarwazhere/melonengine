#pragma once

#ifndef HELPERS_H
#define HELPERS_H

// This is the header file for helper functions

#include "types.h"
#include "entity.h"

void setup();
void setWorld(int size, Player &player);
void tick(int millisecs, Player &player);
bool isPositionInWorld(position pos);
void summonMovingEntity(entityInfo info, float resistance);

#endif // DATA_H