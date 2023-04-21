// This class maintains the implementation for the I class object contained in the I class header file

#include "I.h"

// Default Constructor
// Creates a Tetromino of I_TYPE and initial rotationState of 0
I::I()
{
    type = I_TYPE;
    rotationState = 0;

    pointOne = I_SPAWN_POINT_ONE;
    pointTwo = I_SPAWN_POINT_TWO;
    pointThree = I_SPAWN_POINT_THREE;
    pointFour = I_SPAWN_POINT_FOUR;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
bool I::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 2;    pointOne.second += 1;
                        pointTwo.first += 1;
                        pointThree.second -= 1;
                        pointFour.first -= 1;    pointFour.second -= 2;
                        rotationState = 1;
                        break;
            case 1  :   pointOne.first += 1;    pointOne.second -= 2;
                        pointTwo.second -= 1;
                        pointThree.first -= 1;
                        pointFour.first -= 2;    pointFour.second += 1;
                        rotationState = 2;
                        break;
            case 2  :   pointOne.first -= 2;    pointOne.second -= 1;
                        pointTwo.first -= 1;
                        pointThree.second += 1;
                        pointFour.first += 1;    pointFour.second += 2;
                        rotationState = 3;
                        break;
            case 3  :   pointOne.first -= 1;    pointOne.second += 2;
                        pointTwo.second += 1;
                        pointThree.first += 1;
                        pointFour.first += 2;    pointFour.second -= 1;
                        rotationState = 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 1;    pointOne.second -= 2;
                        pointTwo.second -= 1;
                        pointThree.first -= 1;
                        pointFour.first -= 2;    pointFour.second += 1;
                        rotationState = 3;
                        break;
            case 1  :   pointOne.first -= 2;    pointOne.second -= 1;
                        pointTwo.first -= 1;
                        pointThree.second += 1;
                        pointFour.first += 1;    pointFour.second += 2;
                        rotationState = 0;
                        break;
            case 2  :   pointOne.first -= 1;    pointOne.second += 2;
                        pointTwo.second += 1;
                        pointThree.first += 1;
                        pointFour.first += 2;    pointFour.second -= 1;
                        rotationState = 1;
                        break;
            case 3  :   pointOne.first += 2;    pointOne.second += 1;
                        pointTwo.first += 1;
                        pointThree.second -= 1;
                        pointFour.first -= 1;    pointFour.second -= 2;
                        rotationState = 2;
                        break;
        }
    }
    return true;
}