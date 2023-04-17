// This class maintains the implementation for the I class object contained in the I class header file

#include "I.h"

// Default Constructor
// Creates a Tetromino of I_TYPE and initial rotationState of 0
I::I()
{
    type = I_TYPE;
    rotationState = 0;      //  {0, L, R, 2}

    pointOne = SPAWN_POINT_ONE;
    pointTwo = SPAWN_POINT_TWO;
    pointThree = SPAWN_POINT_THREE;
    pointFour = SPAWN_POINT_FOUR;
}

// Translate piece in the X-Y coordinate plane in the specified direction
// Returns true on successful translation (no collisions), false otherwise
bool I::translate_piece(int x, int y)
{
    return true;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// Returns true on successful rotation (no collisions), false otherwise
bool I::rotate_piece(int direction)
{
    return true;
}