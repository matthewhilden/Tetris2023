// This class maintains the implementation for the GameBoardPanel class contained in the GameBoardPanel class header file

#include "GameBoardFrame.h"

// Default constructor
// Sets size of GameBoardFrame window
GameBoardFrame::GameBoardFrame() : wxFrame(nullptr, wxID_ANY, "Tetris"), visibleSpawn(GAME_BOARD_SPAWN)
{
    // ** NEED TO HANDLE WINDOW RESIZING **

    // Place Starting Piece
    generate_new_active_piece();
    place_active_piece();

    SetSize(WINDOW_X_OFFSET, WINDOW_Y_OFFSET, WINDOW_WIDTH, WINDOW_HEIGHT, wxSIZE_AUTO);
    Show(true);
}

// Generate bag of pieces
// Generates a random assortment of one of each piece type
// This guarantees the player gets one of each type before getting duplicate pieces
void GameBoardFrame::generate_bag()
{
    for (int pieceType = 1; pieceType <= 7; pieceType++)
    {
        bag.push_back(pieceType);
    }

    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    srand(time(&now));
    std::shuffle(std::begin(bag), std::end(bag), std::default_random_engine(now));
}

// Empty the contents of the bag
void GameBoardFrame::empty_bag()
{
    bag.erase(bag.begin(), bag.end());
}

// Full paint functionality for drawing the entire board and contents from blank
// Does a full redraw of the board
void GameBoardFrame::OnPaint(wxPaintEvent & event)
{
    wxPaintDC dc(this);

    // ** WOULD BE COOL TO ADD SINGLE PIECE TETROMINOS, DON'T FILL IN BETWEEN ADJACENT BLOCKS **

    // ** ADD ABILITY TO UPDATE SINGLE CELL AT A TIME **

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
        case KEY_CODE_W             :   move_up();
                                        break;
        case KEY_CODE_A             :   move_left();
                                        break;
        case KEY_CODE_S             :   if (!move_down())
                                        {
                                            remove_full_lines();
                                            generate_new_active_piece();
                                            place_active_piece();
                                            Refresh();
                                        }
                                        break;
        case KEY_CODE_D             :   move_right();
                                        break;
    }
}

// Move active piece UP one position
// Returns true on success, false otherwise
bool GameBoardFrame::move_up()
{
    return translate_active_piece(0, 1);
}

// Move active piece DOWN one position
// Returns true on success, false otherwise
bool GameBoardFrame::move_down()
{
    return translate_active_piece(0, -1);
}

// Move active piece LEFT one position
// Returns true on success, false otherwise
bool GameBoardFrame::move_left()
{
    return translate_active_piece(-1, 0);
}

// Move active piece RIGHT one position
// Returns true on success, false otherwise
bool GameBoardFrame::move_right()
{
    return translate_active_piece(1, 0);
}

// Generates the next active piece in sequence
// Draws from the existing bag, or draws from a new bag if the current
// bag is empty.
void GameBoardFrame::generate_new_active_piece()
{
    if (bag.empty())
    {
        generate_bag();
    }
    int type = bag.front();
    switch(type)
    {
        activePiece = NULL;
        case 1 : activePiece = new I();
                 break;
        case 2 : activePiece = new J();
                 break;
        case 3 : activePiece = new L();
                 break;
        case 4 : activePiece = new O();
                 break;
        case 5 : activePiece = new S();
                 break;
        case 6 : activePiece = new T();
                 break;
        case 7 : activePiece = new Z();
                 break;
    }
    bag.erase(bag.begin());
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
// Returns true on successful movement, false otherwise
// Updates the position of the piece on success
bool GameBoardFrame::translate_active_piece(int x, int y)
{
    remove_active_piece();
    activePiece->translate_piece(x, y);

    std::pair<int, int> updatedPointOne = activePiece->get_point_one();
    std::pair<int, int> updatedPointTwo = activePiece->get_point_two();
    std::pair<int, int> updatedPointThree = activePiece->get_point_three();
    std::pair<int, int> updatedPointFour = activePiece->get_point_four();

    bool withinBoardBoundaries =    gameBoard.within_board_boundaries(updatedPointOne.first, updatedPointOne.second) &&
                                    gameBoard.within_board_boundaries(updatedPointTwo.first, updatedPointTwo.second) &&
                                    gameBoard.within_board_boundaries(updatedPointThree.first, updatedPointThree.second) &&
                                    gameBoard.within_board_boundaries(updatedPointFour.first, updatedPointFour.second);
    if (withinBoardBoundaries)
    {
        bool cellsAreEmpty =    gameBoard.is_cell_empty(updatedPointOne.first, updatedPointOne.second) &&
                                gameBoard.is_cell_empty(updatedPointTwo.first, updatedPointTwo.second) &&
                                gameBoard.is_cell_empty(updatedPointThree.first, updatedPointThree.second) &&
                                gameBoard.is_cell_empty(updatedPointFour.first, updatedPointFour.second);
        if (cellsAreEmpty)
        {
            place_active_piece();
            Refresh();
            return true;
        }
        else
        {
            activePiece->translate_piece(-x, -y);
            place_active_piece();
            return false;
        }
    }
    else
    {
        activePiece->translate_piece(-x, -y);
        place_active_piece();
        return false;
    }
}

// Rotate the active piece in the specified CW/CCW direction
// Returns true if successful, false otherwise
// Rotates the active piece on success
// Attempts a set of wallkicks if a standard rotation fails
// If all 5 attempts fail, the piece does not rotate
bool GameBoardFrame::rotate_active_piece(int direction)
{
    remove_active_piece();
    activePiece->rotate_piece(direction);

    std::pair<int, int> updatedPointOne = activePiece->get_point_one();
    std::pair<int, int> updatedPointTwo = activePiece->get_point_two();
    std::pair<int, int> updatedPointThree = activePiece->get_point_three();
    std::pair<int, int> updatedPointFour = activePiece->get_point_four();

    bool withinBoardBoundaries =    gameBoard.within_board_boundaries(updatedPointOne.first, updatedPointOne.second) &&
                                    gameBoard.within_board_boundaries(updatedPointTwo.first, updatedPointTwo.second) &&
                                    gameBoard.within_board_boundaries(updatedPointThree.first, updatedPointThree.second) &&
                                    gameBoard.within_board_boundaries(updatedPointFour.first, updatedPointFour.second); 
    if (withinBoardBoundaries)
    {
        bool cellsAreEmpty =    gameBoard.is_cell_empty(updatedPointOne.first, updatedPointOne.second) &&
                                gameBoard.is_cell_empty(updatedPointTwo.first, updatedPointTwo.second) &&
                                gameBoard.is_cell_empty(updatedPointThree.first, updatedPointThree.second) &&
                                gameBoard.is_cell_empty(updatedPointFour.first, updatedPointFour.second);
        if (cellsAreEmpty)
        {
            place_active_piece();
            Refresh();
            return true;
        }
        else
        {
            activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);
            place_active_piece();
            rotate_with_wall_kick(direction);
        }
    }
    else
    {
        activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);
        place_active_piece();
        rotate_with_wall_kick(direction);
    }
    return false;
}

// Select desired wallkick table based on Tetromino type
// I_TYPE uses a different table than the other Tetrominos
// Returns true if successful, false otherwise
bool GameBoardFrame::rotate_with_wall_kick(int direction)
{
    if (activePiece->get_type() == I_TYPE)
    {
        return rotate_with_I_TYPE_wallkick_table(direction);
    }
    else
    {
        return rotate_with_non_I_TYPE_wallkick_table(direction);
    }
}

// Parse desired wallkick table based on Tetromino type
// I_TYPE uses a different table than the other Tetrominos
// Returns true if successful, false otherwise
bool GameBoardFrame::rotate_with_non_I_TYPE_wallkick_table(int direction)
{
    int rotationState = activePiece->get_rotation_state();
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   if (rotate_with_wall_kick(ZERO_CLOCKWISE_1.first, ZERO_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ZERO_CLOCKWISE_2.first, ZERO_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ZERO_CLOCKWISE_3.first, ZERO_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ZERO_CLOCKWISE_4.first, ZERO_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 1  :   if (rotate_with_wall_kick(ONE_CLOCKWISE_1.first, ONE_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ONE_CLOCKWISE_2.first, ONE_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ONE_CLOCKWISE_3.first, ONE_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ONE_CLOCKWISE_4.first, ONE_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 2  :   if (rotate_with_wall_kick(TWO_CLOCKWISE_1.first, TWO_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(TWO_CLOCKWISE_2.first, TWO_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(TWO_CLOCKWISE_3.first, TWO_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(TWO_CLOCKWISE_4.first, TWO_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 3  :   if (rotate_with_wall_kick(THREE_CLOCKWISE_1.first, THREE_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(THREE_CLOCKWISE_2.first, THREE_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(THREE_CLOCKWISE_3.first, THREE_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(THREE_CLOCKWISE_4.first, THREE_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
        }
    }
    else
    {
        switch(rotationState)
        {
            case 0  :   if (rotate_with_wall_kick(ZERO_COUNTERCLOCKWISE_1.first, ZERO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ZERO_COUNTERCLOCKWISE_2.first, ZERO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ZERO_COUNTERCLOCKWISE_3.first, ZERO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ZERO_COUNTERCLOCKWISE_4.first, ZERO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 1  :   if (rotate_with_wall_kick(ONE_COUNTERCLOCKWISE_1.first, ONE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ONE_COUNTERCLOCKWISE_2.first, ONE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ONE_COUNTERCLOCKWISE_3.first, ONE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(ONE_COUNTERCLOCKWISE_4.first, ONE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 2  :   if (rotate_with_wall_kick(TWO_COUNTERCLOCKWISE_1.first, TWO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(TWO_COUNTERCLOCKWISE_2.first, TWO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(TWO_COUNTERCLOCKWISE_3.first, TWO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(TWO_COUNTERCLOCKWISE_4.first, TWO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 3  :   if (rotate_with_wall_kick(THREE_COUNTERCLOCKWISE_1.first, THREE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(THREE_COUNTERCLOCKWISE_2.first, THREE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(THREE_COUNTERCLOCKWISE_3.first, THREE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(THREE_COUNTERCLOCKWISE_4.first, THREE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
        }
    }
    return false;
}

// Parse desired wallkick table based on Tetromino type
// I_TYPE uses a different table than the other Tetrominos
// Returns true if successful, false otherwise
bool GameBoardFrame::rotate_with_I_TYPE_wallkick_table(int direction)
{
    int rotationState = activePiece->get_rotation_state();
    if (direction == CLOCKWISE)
    {
        switch(rotationState)
        {
            case 0  :   if (rotate_with_wall_kick(I_ZERO_CLOCKWISE_1.first, I_ZERO_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ZERO_CLOCKWISE_2.first, I_ZERO_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ZERO_CLOCKWISE_3.first, I_ZERO_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ZERO_CLOCKWISE_4.first, I_ZERO_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 1  :   if (rotate_with_wall_kick(I_ONE_CLOCKWISE_1.first, I_ONE_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ONE_CLOCKWISE_2.first, I_ONE_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ONE_CLOCKWISE_3.first, I_ONE_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ONE_CLOCKWISE_4.first, I_ONE_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 2  :   if (rotate_with_wall_kick(I_TWO_CLOCKWISE_1.first, I_TWO_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_TWO_CLOCKWISE_2.first, I_TWO_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_TWO_CLOCKWISE_3.first, I_TWO_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_TWO_CLOCKWISE_4.first, I_TWO_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 3  :   if (rotate_with_wall_kick(I_THREE_CLOCKWISE_1.first, I_THREE_CLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_THREE_CLOCKWISE_2.first, I_THREE_CLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_THREE_CLOCKWISE_3.first, I_THREE_CLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_THREE_CLOCKWISE_4.first, I_THREE_CLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
        }
    }
    else
    {
        switch(rotationState)
        {
            case 0  :   if (rotate_with_wall_kick(I_ZERO_COUNTERCLOCKWISE_1.first, I_ZERO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ZERO_COUNTERCLOCKWISE_2.first, I_ZERO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ZERO_COUNTERCLOCKWISE_3.first, I_ZERO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ZERO_COUNTERCLOCKWISE_4.first, I_ZERO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 1  :   if (rotate_with_wall_kick(I_ONE_COUNTERCLOCKWISE_1.first, I_ONE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ONE_COUNTERCLOCKWISE_2.first, I_ONE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ONE_COUNTERCLOCKWISE_3.first, I_ONE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_ONE_COUNTERCLOCKWISE_4.first, I_ONE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 2  :   if (rotate_with_wall_kick(I_TWO_COUNTERCLOCKWISE_1.first, I_TWO_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_TWO_COUNTERCLOCKWISE_2.first, I_TWO_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_TWO_COUNTERCLOCKWISE_3.first, I_TWO_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_TWO_COUNTERCLOCKWISE_4.first, I_TWO_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
                        break;
            case 3  :   if (rotate_with_wall_kick(I_THREE_COUNTERCLOCKWISE_1.first, I_THREE_COUNTERCLOCKWISE_1.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_THREE_COUNTERCLOCKWISE_2.first, I_THREE_COUNTERCLOCKWISE_2.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_THREE_COUNTERCLOCKWISE_3.first, I_THREE_COUNTERCLOCKWISE_3.second, direction))
                        {
                            return true;
                        }
                        if (rotate_with_wall_kick(I_THREE_COUNTERCLOCKWISE_4.first, I_THREE_COUNTERCLOCKWISE_4.second, direction))
                        {
                            return true;
                        }
        }
    }
    return false;
}

// Rotate the active piece in the specified CW/CCW direction after applying specified X-Y translation
// Returns true if successful, false otherwise
// Rotates and translates the active piece on success
bool GameBoardFrame::rotate_with_wall_kick(int x, int y, int direction)
{
    remove_active_piece();
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
    if (withinBoardBoundaries)
    {
        bool cellsAreEmpty =    gameBoard.is_cell_empty(updatedPointOne.first, updatedPointOne.second) &&
                                gameBoard.is_cell_empty(updatedPointTwo.first, updatedPointTwo.second) &&
                                gameBoard.is_cell_empty(updatedPointThree.first, updatedPointThree.second) &&
                                gameBoard.is_cell_empty(updatedPointFour.first, updatedPointFour.second);
        if (cellsAreEmpty)
        {
            place_active_piece();
            Refresh();
            return true;
        }
        else
        {
            activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);
            activePiece->translate_piece(-x, -y);
            place_active_piece();
        }
    }
    else
    {
        activePiece->rotate_piece(direction == CLOCKWISE ? COUNTERCLOCKWISE : CLOCKWISE);
        activePiece->translate_piece(-x, -y);
        place_active_piece();
    }
    return false;
}

// Removes full lines from the board
// Shifts the contents of the board down vertically as rows are removed
// Returns the number of lines (rows) removed
int GameBoardFrame::remove_full_lines()
{
    int removedLines = 0;
    for (int row = 0; row < BOARD_HEIGHT + BOARD_HEIGHT_BUFFER; row++)
    {
        if (gameBoard.is_row_full(row))
        {
            gameBoard.empty_row(row);
            removedLines++;
        }
        else if (removedLines != 0)
        {
            for (int column = 0; column < BOARD_WIDTH; column++)
            {
                gameBoard.set_cell(column, row - removedLines, gameBoard.get_cell(column, row));
            }
        }
    } 
    return removedLines;
}