// This file maintains the header for the I class object
// The I represents an I Tetromino "stick" piece

#pragma once

#include "Tetromino.h"
#include "Board.h"

const std::pair<int, int> SPAWN_POINT_ONE = std::pair<int, int>(3,1);
const std::pair<int, int> SPAWN_POINT_TWO = std::pair<int, int>(4,1);
const std::pair<int, int> SPAWN_POINT_THREE = std::pair<int, int>(5,1);
const std::pair<int, int> SPAWN_POINT_FOUR = std::pair<int, int>(6,1);

class I : public Tetromino
{
    public:

        I();
        bool translate_piece(int x, int y);
        bool rotate_piece(int direction);
};