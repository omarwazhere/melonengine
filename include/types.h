#pragma once

#ifndef TYPES_H
#define TYPES_H

#include <string>

// This is the header file for data structures

// Entity's position structure 
struct position {
    int x;
    int y;
};

// Entity's velocity structure
struct velocity {
    float resistance;
    float velx;
    float vely;
};

// Entity info structure
struct entityInfo {
    std::string n;
    int startx;
    int starty;
    bool is_solid;
    char symbol;
};

// World info structure
struct worldInfo {
    unsigned int size;
    unsigned int render_dist;
    char air;
};

#endif