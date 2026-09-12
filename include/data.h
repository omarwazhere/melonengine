#pragma once

#ifndef DATA_H
#define DATA_H

struct position {
    int x;
    int y;
};

struct velocity {
    float resistance; // 0.0 -> 1.0
    float velx;
    float vely;
};

#endif // DATA_H