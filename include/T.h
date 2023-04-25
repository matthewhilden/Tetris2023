// This file maintains the header for the T class object
// The T represents an T Tetromino

#pragma once

#include "Tetromino.h"

const std::pair<int, int> T_SPAWN_POINT_ONE = std::pair<int, int>(3,20);
const std::pair<int, int> T_SPAWN_POINT_TWO = std::pair<int, int>(4,20);
const std::pair<int, int> T_SPAWN_POINT_THREE = std::pair<int, int>(4,21);
const std::pair<int, int> T_SPAWN_POINT_FOUR = std::pair<int, int>(5,20);

class T : public Tetromino
{
    public:

        T();
        bool rotate_piece(int direction);
};