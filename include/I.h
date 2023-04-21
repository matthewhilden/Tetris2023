// This file maintains the header for the I class object
// The I represents an I Tetromino "stick" piece

#pragma once

#include "Tetromino.h"

const std::pair<int, int> I_SPAWN_POINT_ONE = std::pair<int, int>(3,20);
const std::pair<int, int> I_SPAWN_POINT_TWO = std::pair<int, int>(4,20);
const std::pair<int, int> I_SPAWN_POINT_THREE = std::pair<int, int>(5,20);
const std::pair<int, int> I_SPAWN_POINT_FOUR = std::pair<int, int>(6,20);

class I : public Tetromino
{
    public:

        I();
        bool rotate_piece(int direction);
};