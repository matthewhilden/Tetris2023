// This class maintains the implementation for the GameBoardPanel class contained in the GameBoardPanel class header file

#include "GameBoardFrame.h"

// Default constructor
// Sets size of GameBoardFrame window
GameBoardFrame::GameBoardFrame() : wxFrame(nullptr, wxID_ANY, "Tetris"), visibleSpawn(GAME_BOARD_SPAWN)
{
    // ** NEED TO HANDLE WINDOW RESIZING **

    // Place Starting Piece
    activePiece = new L();
    place_active_piece();

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

// Handler for user input key presses (down key event)
void GameBoardFrame::OnKeyDown(wxKeyEvent & event)
{
    int keyCode = event.GetKeyCode();

    switch(keyCode)
    {
        case KEY_CODE_ROTATE_CW     :   rotate_active_piece(CLOCKWISE);
                                        break;
        case KEY_CODE_ROTATE_CCW    :   rotate_active_piece(COUNTERCLOCKWISE);
                                        break;
        case KEY_CODE_W             :   translate_active_piece(0, 1);
                                        break;
        case KEY_CODE_A             :   translate_active_piece(-1, 0);
                                        break;
        case KEY_CODE_S             :   translate_active_piece(0, -1);
                                        break;
        case KEY_CODE_D             :   translate_active_piece(1, 0);
                                        break;
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

// Translate the active piece in the specified X-Y direction
void GameBoardFrame::translate_active_piece(int x, int y)
{
    if (check_translation_within_board_boundaries(x, y) && check_translation_cells_are_empty(x, y))
    {
        remove_active_piece();
        activePiece->translate_piece(x, y);
        place_active_piece();
        Refresh();
    }
}

// Rotate the active piece in the specified CW/CCW direction
void GameBoardFrame::rotate_active_piece(int direction)
{
    if (check_rotation_within_board_boundaries(direction) && check_rotation_cells_are_empty(direction))
    {   
        remove_active_piece();
        activePiece->rotate_piece(direction);
        place_active_piece();
        Refresh();
    }
    else
    {
        rotate_active_piece_with_wall_kick(direction);
    }
}

// Check that the input X-Y translation for the current active piece is within the boundaries of the board
// Return true if within the boundaries of the board, false otherwise
bool GameBoardFrame::check_translation_within_board_boundaries(int x, int y)
{
    std::pair<int, int> currentPointOne = activePiece->get_point_one();
    std::pair<int, int> currentPointTwo = activePiece->get_point_two();
    std::pair<int, int> currentPointThree = activePiece->get_point_three();
    std::pair<int, int> currentPointFour = activePiece->get_point_four();

    return  gameBoard.within_board_boundaries(currentPointOne.first + x, currentPointOne.second + y) &&
            gameBoard.within_board_boundaries(currentPointTwo.first + x, currentPointTwo.second + y) &&
            gameBoard.within_board_boundaries(currentPointThree.first + x, currentPointThree.second + y) &&
            gameBoard.within_board_boundaries(currentPointFour.first + x, currentPointFour.second + y);
}

// Check that the input X-Y translation for the current active piece does not collide with another inactive board piece
// Return true if all cells are empty, false otherwise (collision)
bool GameBoardFrame::check_translation_cells_are_empty(int x, int y)
{
    int type = activePiece->get_type();

    std::pair<int, int> currentPointOne = activePiece->get_point_one();
    std::pair<int, int> currentPointTwo = activePiece->get_point_two();
    std::pair<int, int> currentPointThree = activePiece->get_point_three();
    std::pair<int, int> currentPointFour = activePiece->get_point_four();

    gameBoard.set_cell(currentPointOne.first, currentPointOne.second, 0);
    gameBoard.set_cell(currentPointTwo.first, currentPointTwo.second, 0);
    gameBoard.set_cell(currentPointThree.first, currentPointThree.second, 0);
    gameBoard.set_cell(currentPointFour.first, currentPointFour.second, 0);

    bool cellsAreEmpty =    gameBoard.is_cell_empty(currentPointOne.first + x, currentPointOne.second + y) &&
                            gameBoard.is_cell_empty(currentPointTwo.first + x, currentPointTwo.second + y) &&
                            gameBoard.is_cell_empty(currentPointThree.first + x, currentPointThree.second + y) &&
                            gameBoard.is_cell_empty(currentPointFour.first + x, currentPointFour.second + y);
    
    gameBoard.set_cell(currentPointOne.first, currentPointOne.second, type);
    gameBoard.set_cell(currentPointTwo.first, currentPointTwo.second, type);
    gameBoard.set_cell(currentPointThree.first, currentPointThree.second, type);
    gameBoard.set_cell(currentPointFour.first, currentPointFour.second, type);

    return cellsAreEmpty;
}

// Check that the input CW/CCW rotation for the current active piece is within the boundaries of the board
// Return true if within the boundaries of the board, false otherwise
bool GameBoardFrame::check_rotation_within_board_boundaries(int direction)
{
    activePiece->rotate_piece(direction);

    std::pair<int, int> updatedPointOne = activePiece->get_point_one();
    std::pair<int, int> updatedPointTwo = activePiece->get_point_two();
    std::pair<int, int> updatedPointThree = activePiece->get_point_three();
    std::pair<int, int> updatedPointFour = activePiece->get_point_four();

    bool withinBoardBoundaries =    gameBoard.within_board_boundaries(updatedPointOne.first, updatedPointOne.second) &&
                                    gameBoard.within_board_boundaries(updatedPointTwo.first, updatedPointTwo.second) &&
                                    gameBoard.within_board_boundaries(updatedPointThree.first, updatedPointThree.second) &&
                                    gameBoard.within_board_boundaries(updatedPointFour.first, updatedPointFour.second); 

    activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);

    return withinBoardBoundaries;
}

// Check that the input X-Y rotation for the current active piece does not collide with another inactive board piece
// Return true if all cells are empty, false otherwise (collision)
bool GameBoardFrame::check_rotation_cells_are_empty(int direction)
{
    int type = activePiece->get_type();

    std::pair<int, int> currentPointOne = activePiece->get_point_one();
    std::pair<int, int> currentPointTwo = activePiece->get_point_two();
    std::pair<int, int> currentPointThree = activePiece->get_point_three();
    std::pair<int, int> currentPointFour = activePiece->get_point_four();

    gameBoard.set_cell(currentPointOne.first, currentPointOne.second, 0);
    gameBoard.set_cell(currentPointTwo.first, currentPointTwo.second, 0);
    gameBoard.set_cell(currentPointThree.first, currentPointThree.second, 0);
    gameBoard.set_cell(currentPointFour.first, currentPointFour.second, 0);

    activePiece->rotate_piece(direction);

    std::pair<int, int> updatedPointOne = activePiece->get_point_one();
    std::pair<int, int> updatedPointTwo = activePiece->get_point_two();
    std::pair<int, int> updatedPointThree = activePiece->get_point_three();
    std::pair<int, int> updatedPointFour = activePiece->get_point_four();

    bool cellsAreEmpty =    gameBoard.is_cell_empty(updatedPointOne.first, updatedPointOne.second) &&
                            gameBoard.is_cell_empty(updatedPointTwo.first, updatedPointTwo.second) &&
                            gameBoard.is_cell_empty(updatedPointThree.first, updatedPointThree.second) &&
                            gameBoard.is_cell_empty(updatedPointFour.first, updatedPointFour.second);

    activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);

    gameBoard.set_cell(currentPointOne.first, currentPointOne.second, type);
    gameBoard.set_cell(currentPointTwo.first, currentPointTwo.second, type);
    gameBoard.set_cell(currentPointThree.first, currentPointThree.second, type);
    gameBoard.set_cell(currentPointFour.first, currentPointFour.second, type);

    return cellsAreEmpty;
}

// Attempt wall kick rotation
// Applies a X-Y translation to the current active piece before attempting the specified rotation
bool GameBoardFrame::rotate_active_piece_with_wall_kick(int direction)
{
    if (activePiece->get_type() == I_TYPE)
    {
        return parse_I_TYPE_wallkick_table_state_direction(activePiece->get_rotation_state(), direction);
    }
    else
    {
        return parse_wallkick_table_state_direction(activePiece->get_rotation_state(), direction);
    }
}

bool GameBoardFrame::parse_wallkick_table_state_direction(int rotationState, int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   if (check_translation_and_rotation(ZERO_CLOCKWISE_1.first, ZERO_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_CLOCKWISE_1.first, ZERO_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ZERO_CLOCKWISE_2.first, ZERO_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_CLOCKWISE_2.first, ZERO_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ZERO_CLOCKWISE_3.first, ZERO_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_CLOCKWISE_3.first, ZERO_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ZERO_CLOCKWISE_4.first, ZERO_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_CLOCKWISE_4.first, ZERO_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 1  :   if (check_translation_and_rotation(ONE_CLOCKWISE_1.first, ONE_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_CLOCKWISE_1.first, ONE_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ONE_CLOCKWISE_2.first, ONE_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_CLOCKWISE_2.first, ONE_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ONE_CLOCKWISE_3.first, ONE_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_CLOCKWISE_3.first, ONE_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ONE_CLOCKWISE_4.first, ONE_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_CLOCKWISE_4.first, ONE_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 2  :   if (check_translation_and_rotation(TWO_CLOCKWISE_1.first, TWO_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_CLOCKWISE_1.first, TWO_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(TWO_CLOCKWISE_2.first, TWO_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_CLOCKWISE_2.first, TWO_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(TWO_CLOCKWISE_3.first, TWO_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_CLOCKWISE_3.first, TWO_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(TWO_CLOCKWISE_4.first, TWO_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_CLOCKWISE_4.first, TWO_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 3  :   if (check_translation_and_rotation(THREE_CLOCKWISE_1.first, THREE_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_CLOCKWISE_1.first, THREE_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(THREE_CLOCKWISE_2.first, THREE_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_CLOCKWISE_2.first, THREE_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(THREE_CLOCKWISE_3.first, THREE_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_CLOCKWISE_3.first, THREE_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(THREE_CLOCKWISE_4.first, THREE_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_CLOCKWISE_4.first, THREE_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
        }
    }
    else
    {
        switch(rotationState)
        {
            case 0  :   if (check_translation_and_rotation(ZERO_COUNTERCLOCKWISE_1.first, ZERO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_COUNTERCLOCKWISE_1.first, ZERO_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ZERO_COUNTERCLOCKWISE_2.first, ZERO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_COUNTERCLOCKWISE_2.first, ZERO_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ZERO_COUNTERCLOCKWISE_3.first, ZERO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_COUNTERCLOCKWISE_3.first, ZERO_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ZERO_COUNTERCLOCKWISE_4.first, ZERO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ZERO_COUNTERCLOCKWISE_4.first, ZERO_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 1  :   if (check_translation_and_rotation(ONE_COUNTERCLOCKWISE_1.first, ONE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_COUNTERCLOCKWISE_1.first, ONE_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ONE_COUNTERCLOCKWISE_2.first, ONE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_COUNTERCLOCKWISE_2.first, ONE_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ONE_COUNTERCLOCKWISE_3.first, ONE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_COUNTERCLOCKWISE_3.first, ONE_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(ONE_COUNTERCLOCKWISE_4.first, ONE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(ONE_COUNTERCLOCKWISE_4.first, ONE_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 2  :   if (check_translation_and_rotation(TWO_COUNTERCLOCKWISE_1.first, TWO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_COUNTERCLOCKWISE_1.first, TWO_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(TWO_COUNTERCLOCKWISE_2.first, TWO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_COUNTERCLOCKWISE_2.first, TWO_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(TWO_COUNTERCLOCKWISE_3.first, TWO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_COUNTERCLOCKWISE_3.first, TWO_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(TWO_COUNTERCLOCKWISE_4.first, TWO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(TWO_COUNTERCLOCKWISE_4.first, TWO_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 3  :   if (check_translation_and_rotation(THREE_COUNTERCLOCKWISE_1.first, THREE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_COUNTERCLOCKWISE_1.first, THREE_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(THREE_COUNTERCLOCKWISE_2.first, THREE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_COUNTERCLOCKWISE_2.first, THREE_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(THREE_COUNTERCLOCKWISE_3.first, THREE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_COUNTERCLOCKWISE_3.first, THREE_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(THREE_COUNTERCLOCKWISE_4.first, THREE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(THREE_COUNTERCLOCKWISE_4.first, THREE_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
        }
    }
    return false;
}

// ** UPDATE TO DO REMOVE THE SECOND PARSING - UPDATE IN THE CHECK FUNCTION AND JUST DONT UNDO THE ROTATION/TRANSLATION **
bool GameBoardFrame::parse_I_TYPE_wallkick_table_state_direction(int rotationState, int direction)
{
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   if (check_translation_and_rotation(I_ZERO_CLOCKWISE_1.first, I_ZERO_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_CLOCKWISE_1.first, I_ZERO_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ZERO_CLOCKWISE_2.first, I_ZERO_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_CLOCKWISE_2.first, I_ZERO_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ZERO_CLOCKWISE_3.first, I_ZERO_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_CLOCKWISE_3.first, I_ZERO_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ZERO_CLOCKWISE_4.first, I_ZERO_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_CLOCKWISE_4.first, I_ZERO_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 1  :   if (check_translation_and_rotation(I_ONE_CLOCKWISE_1.first, I_ONE_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_CLOCKWISE_1.first, I_ONE_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ONE_CLOCKWISE_2.first, I_ONE_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_CLOCKWISE_2.first, I_ONE_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ONE_CLOCKWISE_3.first, I_ONE_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_CLOCKWISE_3.first, I_ONE_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ONE_CLOCKWISE_4.first, I_ONE_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_CLOCKWISE_4.first, I_ONE_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 2  :   if (check_translation_and_rotation(I_TWO_CLOCKWISE_1.first, I_TWO_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_CLOCKWISE_1.first, I_TWO_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_TWO_CLOCKWISE_2.first, I_TWO_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_CLOCKWISE_2.first, I_TWO_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_TWO_CLOCKWISE_3.first, I_TWO_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_CLOCKWISE_3.first, I_TWO_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_TWO_CLOCKWISE_4.first, I_TWO_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_CLOCKWISE_4.first, I_TWO_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 3  :   if (check_translation_and_rotation(I_THREE_CLOCKWISE_1.first, I_THREE_CLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_CLOCKWISE_1.first, I_THREE_CLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_THREE_CLOCKWISE_2.first, I_THREE_CLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_CLOCKWISE_2.first, I_THREE_CLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_THREE_CLOCKWISE_3.first, I_THREE_CLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_CLOCKWISE_3.first, I_THREE_CLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_THREE_CLOCKWISE_4.first, I_THREE_CLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_CLOCKWISE_4.first, I_THREE_CLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
        }
    }
    else
    {
        switch(rotationState)
        {
            case 0  :   if (check_translation_and_rotation(I_ZERO_COUNTERCLOCKWISE_1.first, I_ZERO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_COUNTERCLOCKWISE_1.first, I_ZERO_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ZERO_COUNTERCLOCKWISE_2.first, I_ZERO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_COUNTERCLOCKWISE_2.first, I_ZERO_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ZERO_COUNTERCLOCKWISE_3.first, I_ZERO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_COUNTERCLOCKWISE_3.first, I_ZERO_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ZERO_COUNTERCLOCKWISE_4.first, I_ZERO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ZERO_COUNTERCLOCKWISE_4.first, I_ZERO_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 1  :   if (check_translation_and_rotation(I_ONE_COUNTERCLOCKWISE_1.first, I_ONE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_COUNTERCLOCKWISE_1.first, I_ONE_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ONE_COUNTERCLOCKWISE_2.first, I_ONE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_COUNTERCLOCKWISE_2.first, I_ONE_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ONE_COUNTERCLOCKWISE_3.first, I_ONE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_COUNTERCLOCKWISE_3.first, I_ONE_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_ONE_COUNTERCLOCKWISE_4.first, I_ONE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_ONE_COUNTERCLOCKWISE_4.first, I_ONE_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 2  :   if (check_translation_and_rotation(I_TWO_COUNTERCLOCKWISE_1.first, I_TWO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_COUNTERCLOCKWISE_1.first, I_TWO_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_TWO_COUNTERCLOCKWISE_2.first, I_TWO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_COUNTERCLOCKWISE_2.first, I_TWO_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_TWO_COUNTERCLOCKWISE_3.first, I_TWO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_COUNTERCLOCKWISE_3.first, I_TWO_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_TWO_COUNTERCLOCKWISE_4.first, I_TWO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_TWO_COUNTERCLOCKWISE_4.first, I_TWO_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
            case 3  :   if (check_translation_and_rotation(I_THREE_COUNTERCLOCKWISE_1.first, I_THREE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_COUNTERCLOCKWISE_1.first, I_THREE_COUNTERCLOCKWISE_1.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_THREE_COUNTERCLOCKWISE_2.first, I_THREE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_COUNTERCLOCKWISE_2.first, I_THREE_COUNTERCLOCKWISE_2.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_THREE_COUNTERCLOCKWISE_3.first, I_THREE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_COUNTERCLOCKWISE_3.first, I_THREE_COUNTERCLOCKWISE_3.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        if (check_translation_and_rotation(I_THREE_COUNTERCLOCKWISE_4.first, I_THREE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            remove_active_piece();
                            activePiece->translate_piece(I_THREE_COUNTERCLOCKWISE_4.first, I_THREE_COUNTERCLOCKWISE_4.second);
                            activePiece->rotate_piece(direction);
                            place_active_piece();
                            Refresh();
                            break;
                        }
                        break;
        }
    }
    return false;
}

bool GameBoardFrame::check_translation_and_rotation(int x, int y, int direction)
{
    std::pair<int, int> currentPointOne = activePiece->get_point_one();
    std::pair<int, int> currentPointTwo = activePiece->get_point_two();
    std::pair<int, int> currentPointThree = activePiece->get_point_three();
    std::pair<int, int> currentPointFour = activePiece->get_point_four();

    gameBoard.set_cell(currentPointOne.first, currentPointOne.second, 0);
    gameBoard.set_cell(currentPointTwo.first, currentPointTwo.second, 0);
    gameBoard.set_cell(currentPointThree.first, currentPointThree.second, 0);
    gameBoard.set_cell(currentPointFour.first, currentPointFour.second, 0);

    activePiece->translate_piece(x, y);
    activePiece->rotate_piece(direction);

    std::pair<int, int> updatedPointOne = activePiece->get_point_one();
    std::pair<int, int> updatedPointTwo = activePiece->get_point_two();
    std::pair<int, int> updatedPointThree = activePiece->get_point_three();
    std::pair<int, int> updatedPointFour = activePiece->get_point_four();

    bool withinBoardBoundaries =    gameBoard.within_board_boundaries(updatedPointOne.first, updatedPointOne.second) &&
                                    gameBoard.within_board_boundaries(updatedPointTwo.first, updatedPointTwo.second) &&
                                    gameBoard.within_board_boundaries(updatedPointThree.first, updatedPointThree.second) &&
                                    gameBoard.within_board_boundaries(updatedPointFour.first, updatedPointFour.second);
    
    if (!withinBoardBoundaries)
    {
        activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);
        activePiece->translate_piece(-x, -y);
        return withinBoardBoundaries;
    }

    bool cellsAreEmpty =    gameBoard.is_cell_empty(updatedPointOne.first, updatedPointOne.second) &&
                            gameBoard.is_cell_empty(updatedPointTwo.first, updatedPointTwo.second) &&
                            gameBoard.is_cell_empty(updatedPointThree.first, updatedPointThree.second) &&
                            gameBoard.is_cell_empty(updatedPointFour.first, updatedPointFour.second);

    activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);
    activePiece->translate_piece(-x, -y);

    return withinBoardBoundaries && cellsAreEmpty;
}