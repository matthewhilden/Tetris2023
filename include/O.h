// This file maintains the header for the O class object
// The I represents an O Tetromino

#pragma once

#include "Tetromino.h"

const std::pair<int, int> O_SPAWN_POINT_ONE = std::pair<int, int>(4,21);
const std::pair<int, int> O_SPAWN_POINT_TWO = std::pair<int, int>(5,21);
const std::pair<int, int> O_SPAWN_POINT_THREE = std::pair<int, int>(4,20);
const std::pair<int, int> O_SPAWN_POINT_FOUR = std::pair<int, int>(5,20);

class O : public Tetromino
{
    public:

        O();
        bool rotate_piece(int direction);
};