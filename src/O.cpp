// This class maintains the implementation for the O class object contained in the O class header file

#include "O.h"

// Default Constructor
// Creates a Tetromino of O_TYPE and initial rotationState of 0
O::O()
{
    type = O_TYPE;
    rotationState = 0;

    pointOne = O_SPAWN_POINT_ONE;
    pointTwo = O_SPAWN_POINT_TWO;
    pointThree = O_SPAWN_POINT_THREE;
    pointFour = O_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// An O Tetromino does not rotate, or a rotation does not result in any changed positions
bool O::rotate_piece(int direction)
{
    return true;
}