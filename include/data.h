#pragma once

#ifndef DATA_H
#define DATA_H

/*
This is the header file for data structures,
some global variables,
and helper functions
*/

#include <string>

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

// Helper functions

void setup();

#endif // DATA_H