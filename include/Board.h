// This File maintains the header for the board class object
// A standard TETRIS board is of width 10 and height 20 cells

// Row 0 represents the bottom of the board, Row 21 represents the top of the board (20-21 are not visible)

#pragma once

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int BOARD_HEIGHT_BUFFER = 2;      // Non-visible rows of the board (spawn locations)

class Board
{
    public:
    
        Board();

        int get_cell(int column, int row);
        int set_cell(int column, int row, int value);
        bool is_cell_empty(int column, int row);
        void empty_board();

    private:

        int allCells[BOARD_WIDTH][BOARD_HEIGHT + BOARD_HEIGHT_BUFFER];
};