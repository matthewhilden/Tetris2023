// This class maintains the implementation for the Board class contained in the board class header file

#include <iostream>
#include <stdexcept>

#include "Board.h"

Board::Board()
{
    for (int column = 0; column < BOARD_WIDTH; column++)
    {
        for (int row = 0; row < BOARD_HEIGHT + BOARD_HEIGHT_BUFFER; row++)
        {
            allCells[column][row] = EMPTY_CELL;
        }
    }
}

// Return the value at the specified X-Y (column, row) coordinate
// Returns the value of the cell if within the area of the board, -1 otherwise
// Throws out_of_range exception if X-Y coordinate is outside boundary of board
int Board::get_cell(int column, int row)
{
    // ** DETERMINE WHETHER OR NOT BOUNDARY CONDITIONS SHOULD THROW ERRORS **
    // IF WE CHECK OUTSIDE BOUNDARY OF BOARD WE SHOULD JUST RETURN -1 AND ASSUME COLLISION

    try
    {
        if (column < 0 || column >= BOARD_WIDTH || row < 0 || row >= BOARD_HEIGHT + BOARD_HEIGHT_BUFFER)
        {
            throw std::out_of_range("Out of Range of Board!");
        }
        else
        {
            return allCells[column][row];
        }
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}

int Board::set_cell(int column, int row, int value)
{
    try
    {
        if (column < 0 || column >= BOARD_WIDTH || row < 0 || row >= BOARD_HEIGHT + BOARD_HEIGHT_BUFFER)
        {
            throw std::out_of_range("Out of Range of Board!");
        }
        else
        {
            allCells[column][row] = value;
            return value;
        }
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Check if the specified X-Y (column, row) coordinate is empty (value = 0)
// Returns true if the cell is empty, false otherwise
// Throws out_of_range exception if X-Y coordinate is outside boundary of board
bool Board::is_cell_empty(int column, int row)
{
    try
    {
        if (column < 0 || column >= BOARD_WIDTH || row < 0 || row >= BOARD_HEIGHT + BOARD_HEIGHT_BUFFER)
        {
            throw std::out_of_range("Out of Range of Board!");
        }
        else
        {
            return allCells[column][row] == EMPTY_CELL;
        }
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }   
}

// Empty contents of entire board
// Sets each and every cell of the board to its default value of 0
void Board::empty_board()
{
   for (int column = 0; column < BOARD_WIDTH; column++)
    {
        for (int row = 0; row < BOARD_HEIGHT + BOARD_HEIGHT_BUFFER; row++)
        {
            allCells[column][row] = EMPTY_CELL;
        }
    }
}