// This file maintains the header for the tetromino class object interface
// A Tetromino represents the interface and functionality of a Tetris piece
// The Tetromino class is inherited by all other Tetromino pieces

#pragma once

#include <utility>

const int I_TYPE = 1;
const int J_TYPE = 2;
const int L_TYPE = 3;
const int O_TYPE = 4;
const int S_TYPE = 5;
const int T_TYPE = 6;
const int Z_TYPE = 7;

const int CLOCKWISE = 0;
const int COUNTERCLOCKWISE = 1;

class Tetromino
{
    public:

        virtual bool translate_piece(int x, int y)
        {
            pointOne.first += x;        pointOne.second += y;
            pointTwo.first += x;        pointTwo.second += y;
            pointThree.first += x;      pointThree.second += y;
            pointFour.first += x;       pointFour.second += y;
        };
        
        virtual bool rotate_piece(int rotation) = 0;

        int get_type() { return type; };
        int get_rotation_state() { return rotationState; };
        std::pair<int, int> get_point_one() { return pointOne; };
        std::pair<int, int> get_point_two() { return pointTwo; };
        std::pair<int, int> get_point_three() { return pointThree; };
        std::pair<int, int> get_point_four() { return pointFour; };


    protected:

        int type;
        int rotationState;
        std::pair<int, int> pointOne;
        std::pair<int, int> pointTwo;
        std::pair<int, int> pointThree;
        std::pair<int, int> pointFour;

};