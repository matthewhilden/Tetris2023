// This file maintains the header for the Z class object
// The Z represents an Z Tetromino

#pragma once

#include "Tetromino.h"

const std::pair<int, int> Z_SPAWN_POINT_ONE = std::pair<int, int>(3,21);
const std::pair<int, int> Z_SPAWN_POINT_TWO = std::pair<int, int>(4,21);
const std::pair<int, int> Z_SPAWN_POINT_THREE = std::pair<int, int>(4,20);
const std::pair<int, int> Z_SPAWN_POINT_FOUR = std::pair<int, int>(5,20);

class Z : public Tetromino
{
    public:

        Z();
        bool rotate_piece(int direction);
};