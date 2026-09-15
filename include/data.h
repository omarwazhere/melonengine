#pragma once

#ifndef DATA_H
#define DATA_H

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

#endif // DATA_H