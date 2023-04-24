// This file maintains the header for the J class object
// The J represents an J Tetromino

#pragma once

#include "Tetromino.h"

const std::pair<int, int> J_SPAWN_POINT_ONE = std::pair<int, int>(3,21);
const std::pair<int, int> J_SPAWN_POINT_TWO = std::pair<int, int>(3,20);
const std::pair<int, int> J_SPAWN_POINT_THREE = std::pair<int, int>(4,20);
const std::pair<int, int> J_SPAWN_POINT_FOUR = std::pair<int, int>(5,20);

class J : public Tetromino
{
    public:

        J();
        bool rotate_piece(int direction);
};