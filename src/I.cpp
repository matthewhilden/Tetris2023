// This class maintains the implementation for the I class object contained in the I class header file

#include "I.h"

// Default Constructor
// Creates a Tetromino of I_TYPE and initial rotationState of 0
I::I()
{
    type = I_TYPE;
    rotationState = 0;      //  {0, 1 ("Right"), 2, 3 ("Left")}

    pointOne = SPAWN_POINT_ONE;
    pointTwo = SPAWN_POINT_TWO;
    pointThree = SPAWN_POINT_THREE;
    pointFour = SPAWN_POINT_FOUR;
}

// Translate piece in the X-Y coordinate plane in the specified direction
bool I::translate_piece(int x, int y)
{
    pointOne.first += x;        pointOne.second += y;
    pointTwo.first += x;        pointTwo.second += y;
    pointThree.first += x;      pointThree.second += y;
    pointFour.first += x;       pointFour.second += y;
    return true;
}

// Rotate piece in specified direction, either clockwise or counterclockwise
bool I::rotate_piece(int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   pointOne.first += 2;    pointOne.second += 1;
                        pointTwo.first += 1;    pointTwo.second += 0;
                        pointThree.first += 0;    pointThree.second -= 1;
                        pointFour.first -= 1;    pointFour.second -= 2;
                        rotationState++;
                        break;
            case 1  :   pointOne.first += 1;    pointOne.second -= 2;
                        pointTwo.first += 0;    pointTwo.second -= 1;
                        pointThree.first -= 1;    pointThree.second -= 0;
                        pointFour.first -= 2;    pointFour.second += 1;
                        rotationState++;
                        break;
            case 2  :   pointOne.first -= 2;    pointOne.second -= 1;
                        pointTwo.first -= 1;    pointTwo.second -= 0;
                        pointThree.first -= 0;    pointThree.second += 1;
                        pointFour.first += 1;    pointFour.second += 2;
                        rotationState++;
                        break;
            case 3  :   pointOne.first -= 1;    pointOne.second += 2;
                        pointTwo.first -= 0;    pointTwo.second += 1;
                        pointThree.first += 1;    pointThree.second += 0;
                        pointFour.first += 2;    pointFour.second -= 1;
                        rotationState == 0;
        }
    }
    else if (direction == COUNTERCLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   break;
            case 1  :   break;
            case 2  :   break;
            case 3  :   break;
        }
    }
    return true;
}