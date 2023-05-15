// This class maintains the implementation for the Board class contained in the board class header file

#include <iostream>
#include <stdexcept>

#include "Board.h"

// Default constructor
// Sets all cells of the 2D array to empty (Default value = 0)
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
// Throws out_of_range exception if X-Y coordinate is outside the boundaries of board
int Board::get_cell(int column, int row)
{
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

// Set the cell at the specified X-Y (column, row) to the input value
// Returns the value of the cell if successful,
// throws out_of_range exception if the X-Y coordinate is outside the boundaries of the board
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
// Throws out_of_range exception if X-Y coordinate is outside the boundaries of board
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

// Check if the specified X-Y (column, row) coordinate is within the boundaries of the board
// Returns true if the coordinate is within the boundaries of the board, false otherwise
// 0 <= column  < BOARD_WIDTH
// 0 <= row     < BOARD_HEIGHT + BOARD_HEIGHT_BUFFER
bool Board::within_board_boundaries(int column, int row)
{
    if (column >= 0 && column < BOARD_WIDTH && row >= 0 && row < BOARD_HEIGHT + BOARD_HEIGHT_BUFFER)
    {
        return true;
    }
    return false;
}

// Check if the specified row is full
// Returns true if the entire row is full (non-zero values), false otherwise
// Throws out_of_range exception if Y coordinate (row) is outside the boundaries of board
bool Board::is_row_full(int row)
{
    try
    {
        if (row < 0 || row >= BOARD_HEIGHT + BOARD_HEIGHT_BUFFER)
        {
            throw std::out_of_range("Out of Range of Board!");
        }
        else
        {
            for (int column = 0; column < BOARD_WIDTH; column++)
            {
                if (allCells[column][row] == EMPTY_CELL)
                {
                    return false;
                }
            }
            return true;
        }
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }   
}

// Empty the specified row
// Sets contents of entire row to zero (empty)
// Throws out_of_range exception if Y coordinate (row) is outside the boundaries of board
void Board::empty_row(int row)
{
    try
    {
        if (row < 0 || row >= BOARD_HEIGHT + BOARD_HEIGHT_BUFFER)
        {
            throw std::out_of_range("Out of Range of Board!");
        }
        else
        {
            for (int column = 0; column < BOARD_WIDTH; column++)
            {
                allCells[column][row] = EMPTY_CELL;
            }
        }
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}