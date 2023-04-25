// This file maintains the header for the S class object
// The S represents an S Tetromino

#pragma once

#include "Tetromino.h"

const std::pair<int, int> S_SPAWN_POINT_ONE = std::pair<int, int>(3,20);
const std::pair<int, int> S_SPAWN_POINT_TWO = std::pair<int, int>(4,20);
const std::pair<int, int> S_SPAWN_POINT_THREE = std::pair<int, int>(4,21);
const std::pair<int, int> S_SPAWN_POINT_FOUR = std::pair<int, int>(5,21);

class S : public Tetromino
{
    public:

        S();
        bool rotate_piece(int direction);
};