// This class maintains the implementation for the Z class object contained in the Z class header file

#include "Z.h"

// Default Constructor
// Creates a Tetromino of Z_TYPE and initial rotationState of 0
Z::Z()
{
    type = Z_TYPE;
    rotationState = 0;

    pointOne = Z_SPAWN_POINT_ONE;
    pointTwo = Z_SPAWN_POINT_TWO;
    pointThree = Z_SPAWN_POINT_THREE;
    pointFour = Z_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// PointThree is considered the pivot point, and does not move during rotation
bool Z::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 2;
                        pointTwo.first += 1;    pointTwo.second -= 1;
                        pointFour.first -= 1;   pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 1  :   pointOne.second -= 2;
                        pointTwo.first -= 1;    pointTwo.second -= 1;
                        pointFour.first -= 1;   pointFour.second += 1;
                        rotationState = 2;
                        break;
            case 2  :   pointOne.first -= 2;
                        pointTwo.first -= 1;    pointTwo.second += 1;
                        pointFour.first += 1;   pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 3  :   pointOne.second += 2;
                        pointTwo.first += 1;    pointTwo.second += 1;
                        pointFour.first += 1;   pointFour.second -= 1;
                        rotationState = 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
           case 0  :    pointOne.second -= 2;
                        pointTwo.first -= 1;    pointTwo.second -= 1;
                        pointFour.first -= 1;   pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 1  :   pointOne.first -= 2;
                        pointTwo.first -= 1;    pointTwo.second += 1;
                        pointFour.first += 1;   pointFour.second += 1;
                        rotationState = 0;
                        break;
            case 2  :   pointOne.second += 2;
                        pointTwo.first += 1;    pointTwo.second += 1;
                        pointFour.first += 1;   pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 3  :   pointOne.first += 2;
                        pointTwo.first += 1;    pointTwo.second -= 1;
                        pointFour.first -= 1;   pointFour.second -= 1;
                        rotationState = 2;
        }
    }
    return true;
}