#pragma once

#ifndef HELPERS_H
#define HELPERS_H

#include "types.h"
#include "entity.h"

// This is the header file for helper functions

void setup();
void setWorld(int size);
void tick(int millisecs, int renderx, int rendery);
bool isPositionInWorld(position pos);
void summonMovingEntity(entityInfo &info);
void summonObject(entityInfo &info);
bool checkSolidEntity(position pos, unsigned int id);

#endif // DATA_H