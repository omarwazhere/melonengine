#pragma once

#ifndef HELPERS_H
#define HELPERS_H

// This is the header file for helper functions

#include "types.h"
#include "entity.h"

void setup();
void setWorld(int size);
void tick(int millisecs, int renderx, int rendery);
bool isPositionInWorld(position pos);
void summonMovingEntity(entityInfo &info);
bool checkSolidEntity(position pos, unsigned int id);

#endif // DATA_H