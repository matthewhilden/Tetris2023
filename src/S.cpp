// This class maintains the implementation for the S class object contained in the S class header file

#include "S.h"

// Default Constructor
// Creates a Tetromino of S_TYPE and initial rotationState of 0
S::S()
{
    type = S_TYPE;
    rotationState = 0;

    pointOne = S_SPAWN_POINT_ONE;
    pointTwo = S_SPAWN_POINT_TWO;
    pointThree = S_SPAWN_POINT_THREE;
    pointFour = S_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// PointTwo is considered the pivot point, and does not move during rotation
bool S::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second -= 1;
                        pointFour.second -= 2;
                        rotationState = 1;
                        break;
            case 1  :   pointOne.first += 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second -= 1;
                        pointFour.first -= 2;
                        rotationState = 2;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second += 1;
                        pointFour.second += 2;
                        rotationState = 3;
                        break;
            case 3  :   pointOne.first -= 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second += 1;
                        pointFour.first += 2;
                        rotationState = 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second -= 1;
                        pointFour.first -= 2;
                        rotationState = 3;
                        break;
            case 1  :   pointOne.first -= 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second += 1;
                        pointFour.second += 2;
                        rotationState = 0;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second += 1;
                        pointFour.first += 2;
                        rotationState = 1;
                        break;
            case 3  :   pointOne.first += 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second -= 1;
                        pointFour.second -= 2;
                        rotationState = 2;
                        break;
        }
    }
    return true;
}