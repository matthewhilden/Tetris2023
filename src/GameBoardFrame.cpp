// This class maintains the implementation for the GameBoardPanel class contained in the GameBoardPanel class header file

#include "GameBoardFrame.h"

// Default constructor
// Sets size of GameBoardFrame window
GameBoardFrame::GameBoardFrame() : wxFrame(nullptr, wxID_ANY, "Tetris"), visibleSpawn(GAME_BOARD_SPAWN)
{
    // ** NEED TO HANDLE WINDOW RESIZING **

    // Place Starting Piece
    //activePiece = new I();
    //place_active_piece();

    SetSize(WINDOW_X_OFFSET, WINDOW_Y_OFFSET, WINDOW_WIDTH, WINDOW_HEIGHT, wxSIZE_AUTO);
    Show(true);
}

// Full paint functionality for drawing the entire board and contents from blank
// Does a full redraw of the board
void GameBoardFrame::OnPaint(wxPaintEvent & event)
{
    wxPaintDC dc(this);

    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(wxRect(FRAME_BOARD_X_OFFSET, FRAME_BOARD_Y_OFFSET, FRAME_BOARD_WIDTH, FRAME_BOARD_HEIGHT));

    for (int column = 0; column < BOARD_WIDTH; column++)
    {
        for (int row = 0; row < BOARD_HEIGHT; row++)
        {
            int x_coord = FRAME_BOARD_X_OFFSET + column * FRAME_BOARD_CELL_WIDTH;
            int y_coord = FRAME_BOARD_Y_OFFSET + (BOARD_HEIGHT - 1 - row) * FRAME_BOARD_CELL_HEIGHT;
            int cell_value = gameBoard.get_cell(column, row);
            switch (cell_value)
            {
                case 1  :   dc.SetBrush(*wxCYAN_BRUSH);
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                case 2  :   dc.SetBrush(*wxBLUE_BRUSH);
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                case 3  :   dc.SetBrush(wxBrush(ORANGE, wxBRUSHSTYLE_SOLID));
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                case 4  :   dc.SetBrush(*wxYELLOW_BRUSH);
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                case 5  :   dc.SetBrush(*wxGREEN_BRUSH);
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                case 6  :   dc.SetBrush(wxBrush(PURPLE, wxBRUSHSTYLE_SOLID));
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                case 7  :   dc.SetBrush(*wxRED_BRUSH);
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                            break;
                default :   dc.SetBrush(*wxTRANSPARENT_BRUSH);      // For testing purposes
                            dc.SetPen(*wxGREY_PEN);
                            dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
            }
        }
    }
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    dc.DrawRectangle(wxRect(FRAME_BOARD_X_OFFSET, FRAME_BOARD_Y_OFFSET, FRAME_BOARD_WIDTH, FRAME_BOARD_HEIGHT));

    if (visibleSpawn)  // Print spawn rows if desired
    {
        int spawn_y_height = BOARD_HEIGHT_BUFFER * FRAME_BOARD_CELL_HEIGHT;
        int spawn_y_offset = FRAME_BOARD_Y_OFFSET - spawn_y_height;

        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.SetBrush(*wxWHITE_BRUSH);
        dc.DrawRectangle(wxRect(FRAME_BOARD_X_OFFSET, spawn_y_offset, FRAME_BOARD_WIDTH, spawn_y_height));

        for (int column = 0; column < BOARD_WIDTH; column++)
        {
            for (int row = BOARD_HEIGHT_BUFFER; row > 0; row--)
            {
                int x_coord = FRAME_BOARD_X_OFFSET + (column * FRAME_BOARD_CELL_WIDTH);
                int y_coord = FRAME_BOARD_Y_OFFSET - (row * FRAME_BOARD_CELL_HEIGHT);
                int cell_value = gameBoard.get_cell(column, row + BOARD_HEIGHT - 1);
                switch (cell_value)
                {
                    case 1  :   dc.SetBrush(*wxCYAN_BRUSH);
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    case 2  :   dc.SetBrush(*wxBLUE_BRUSH);
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    case 3  :   dc.SetBrush(wxBrush(ORANGE, wxBRUSHSTYLE_SOLID));
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    case 4  :   dc.SetBrush(*wxYELLOW_BRUSH);
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    case 5  :   dc.SetBrush(*wxGREEN_BRUSH);
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    case 6  :   dc.SetBrush(wxBrush(PURPLE, wxBRUSHSTYLE_SOLID));
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    case 7  :   dc.SetBrush(*wxRED_BRUSH);
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                                break;
                    default :   dc.SetBrush(*wxTRANSPARENT_BRUSH);      // For testing purposes
                                dc.SetPen(*wxGREY_PEN);
                                dc.DrawRectangle(wxRect(x_coord, y_coord, FRAME_BOARD_CELL_WIDTH, FRAME_BOARD_CELL_HEIGHT));
                }
            }
        }
        dc.SetPen(*wxBLACK_PEN);
        dc.SetBrush(*wxTRANSPARENT_BRUSH);
        dc.DrawRectangle(wxRect(FRAME_BOARD_X_OFFSET, spawn_y_offset, FRAME_BOARD_WIDTH, spawn_y_height));  
    }
}

// Place active piece on the Game Board
void GameBoardFrame::place_active_piece()
{
    int type = activePiece->get_type();
    std::pair<int, int> pointOne = activePiece->get_point_one();
    std::pair<int, int> pointTwo = activePiece->get_point_two();
    std::pair<int, int> pointThree = activePiece->get_point_three();
    std::pair<int, int> pointFour = activePiece->get_point_four();

    gameBoard.set_cell(pointOne.first, pointOne.second, type);
    gameBoard.set_cell(pointTwo.first, pointTwo.second, type);
    gameBoard.set_cell(pointThree.first, pointThree.second, type);
    gameBoard.set_cell(pointFour.first, pointFour.second, type);
}

// Remove active piece on the Game Board
void GameBoardFrame::remove_active_piece()
{
    std::pair<int, int> pointOne = activePiece->get_point_one();
    std::pair<int, int> pointTwo = activePiece->get_point_two();
    std::pair<int, int> pointThree = activePiece->get_point_three();
    std::pair<int, int> pointFour = activePiece->get_point_four();

    gameBoard.set_cell(pointOne.first, pointOne.second, 0);
    gameBoard.set_cell(pointTwo.first, pointTwo.second, 0);
    gameBoard.set_cell(pointThree.first, pointThree.second, 0);
    gameBoard.set_cell(pointFour.first, pointFour.second, 0);   
}