// This class maintains the implementation for the T class object contained in the T class header file

#include "T.h"

// Default Constructor
// Creates a Tetromino of T_TYPE and initial rotationState of 0
T::T()
{
    type = T_TYPE;
    rotationState = 0;

    pointOne = T_SPAWN_POINT_ONE;
    pointTwo = T_SPAWN_POINT_TWO;
    pointThree = T_SPAWN_POINT_THREE;
    pointFour = T_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// PointTwo is considered the pivot point, and does not move during rotation
bool T::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second -= 1;
                        pointFour.first -= 1;   pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 1  :   pointOne.first += 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second -= 1;
                        pointFour.first -= 1;   pointFour.second += 1;
                        rotationState = 2;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second += 1;
                        pointFour.first += 1;   pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 3  :   pointOne.first -= 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second += 1;
                        pointFour.first += 1;   pointFour.second -= 1;
                        rotationState = 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second -= 1;
                        pointFour.first -= 1;   pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 1  :   pointOne.first -= 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second += 1;
                        pointFour.first += 1;   pointFour.second += 1;
                        rotationState = 0;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second += 1;
                        pointFour.first += 1;   pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 3  :   pointOne.first += 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second -= 1;
                        pointFour.first -= 1;   pointFour.second -= 1;
                        rotationState = 2;
        }
    }
    return true;
}