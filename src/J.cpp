// This class maintains the implementation for the J class object contained in the J class header file

#include "J.h"

// Default Constructor
// Creates a Tetromino of J_TYPE and initial rotationState of 0
J::J()
{
    type = J_TYPE;
    rotationState = 0;

    pointOne = J_SPAWN_POINT_ONE;
    pointTwo = J_SPAWN_POINT_TWO;
    pointThree = J_SPAWN_POINT_THREE;
    pointFour = J_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// PointThree is considered the pivot point, and does not move during rotation
bool J::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 2;
                        pointTwo.first += 1;    pointTwo.second += 1;
                        pointFour.first -= 1;   pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 1  :   pointOne.second -= 2;
                        pointTwo.first += 1;    pointTwo.second -= 1;
                        pointFour.first -= 1;   pointFour.second += 1;
                        rotationState = 2;
                        break;
            case 2  :   pointOne.first -= 2;
                        pointTwo.first -= 1;    pointTwo.second -= 1;
                        pointFour.first += 1;   pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 3  :   pointOne.second += 2;
                        pointTwo.first -= 1;    pointTwo.second += 1;
                        pointFour.first += 1;   pointFour.second -= 1;
                        rotationState = 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.second -= 2;
                        pointTwo.first += 1;    pointTwo.second -= 1;
                        pointFour.first -= 1;   pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 1  :   pointOne.first -= 2;
                        pointTwo.first -= 1;    pointTwo.second -= 1;
                        pointFour.first += 1;   pointFour.second += 1;
                        rotationState = 0;
                        break;
            case 2  :   pointOne.second += 2;
                        pointTwo.first -= 1;    pointTwo.second += 1;
                        pointFour.first += 1;   pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 3  :   pointOne.first += 2;
                        pointTwo.first += 1;    pointTwo.second += 1;
                        pointFour.first -= 1;   pointFour.second -= 1;
                        rotationState = 2;
                        break;
        }
    }
    return true;
}