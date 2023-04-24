// This class maintains the implementation for the L class object contained in the L class header file

#include "L.h"

// Default Constructor
// Creates a Tetromino of O_TYPE and initial rotationState of 0
L::L()
{
    type = L_TYPE;
    rotationState = 0;

    pointOne = L_SPAWN_POINT_ONE;
    pointTwo = L_SPAWN_POINT_TWO;
    pointThree = L_SPAWN_POINT_THREE;
    pointFour = L_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
// PointTwo is considered the pivot point, and does not move during rotation
bool L::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second += 1;
                        pointThree.first -= 1;  pointThree.second -= 1;
                        pointFour.second -= 2;
                        rotationState = 1;
                        break;
            case 1  :   pointOne.first += 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second += 1;
                        pointFour.first -= 2;
                        rotationState = 2;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second -= 1;
                        pointThree.first += 1;  pointThree.second += 1;
                        pointFour.second += 2;
                        rotationState = 3;
                        break;
            case 3  :   pointOne.first -= 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second -= 1;
                        pointFour.first += 2;
                        rotationState = 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second -= 1;
                        pointThree.first -= 1;  pointThree.second += 1;
                        pointFour.first -= 2;
                        rotationState = 3;
                        break;
            case 1  :   pointOne.first -= 1;    pointOne.second -= 1;
                        pointThree.first += 1;  pointThree.second += 1;
                        pointFour.second += 2;
                        rotationState = 0;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second += 1;
                        pointThree.first += 1;  pointThree.second -= 1;
                        pointFour.first += 2;
                        rotationState = 1;
                        break;
            case 3  :   pointOne.first += 1;    pointOne.second += 1;
                        pointThree.first -= 1;  pointThree.second -= 1;
                        pointFour.second -= 2;
                        rotationState = 2;
                        break;
        }
    }
    return true;
}