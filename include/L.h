// This file maintains the header for the L class object
// The L represents an L Tetromino

#pragma once

#include "Tetromino.h"

const std::pair<int, int> L_SPAWN_POINT_ONE = std::pair<int, int>(3,20);
const std::pair<int, int> L_SPAWN_POINT_TWO = std::pair<int, int>(4,20);
const std::pair<int, int> L_SPAWN_POINT_THREE = std::pair<int, int>(5,20);
const std::pair<int, int> L_SPAWN_POINT_FOUR = std::pair<int, int>(5,21);

class L : public Tetromino
{
    public:

        L();
        bool rotate_piece(int direction);
};