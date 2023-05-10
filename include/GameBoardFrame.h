// This File maintains the header for the GameBoardPanel class object

#pragma once

#include <wx/wx.h>
#include <wx/wxprec.h>

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "Board.h"
#include "I.h"
#include "J.h"
#include "L.h"
#include "O.h"
#include "S.h"
#include "T.h"
#include "Z.h"
#include "Tetromino.h"
#include "Wallkick.h"


// Default Game Conditions
const bool GAME_BOARD_SPAWN = true;


// Custom Colors
const wxColour ORANGE = wxColor(255, 165, 0);
const wxColour PURPLE = wxColour(128, 0, 128);


// Default Window/Board Size
const int WINDOW_X_OFFSET = 500;
const int WINDOW_Y_OFFSET = 25;
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 1000;
const double WINDOW_HEIGHT_RATIO = 0.8;
const int FRAME_BOARD_HEIGHT = WINDOW_HEIGHT_RATIO * WINDOW_HEIGHT;
const int FRAME_BOARD_WIDTH = FRAME_BOARD_HEIGHT / 2;
const int FRAME_BOARD_X_OFFSET = (WINDOW_WIDTH / 2) - (FRAME_BOARD_WIDTH / 2);
const int FRAME_BOARD_Y_OFFSET = (WINDOW_HEIGHT / 2) - (FRAME_BOARD_HEIGHT / 2);
const int FRAME_BOARD_CELL_HEIGHT = FRAME_BOARD_HEIGHT / BOARD_HEIGHT;
const int FRAME_BOARD_CELL_WIDTH = FRAME_BOARD_WIDTH / BOARD_WIDTH;


// Default Key Bindings
const int KEY_CODE_ROTATE_CW = WXK_RIGHT;
const int KEY_CODE_ROTATE_CCW = WXK_LEFT;
const int KEY_CODE_W = 87;
const int KEY_CODE_A = 65;
const int KEY_CODE_S = 83;
const int KEY_CODE_D = 68;


class GameBoardFrame : public wxFrame
{
    public:

        GameBoardFrame();

        bool move_up();
        bool move_down();
        bool move_left();
        bool move_right();

        DECLARE_EVENT_TABLE();

    private:

        bool visibleSpawn;
        Board gameBoard;
        Tetromino * activePiece;
        std::vector<int> bag;

        void OnPaint(wxPaintEvent & event);
        void OnKeyDown(wxKeyEvent & event);

        void generate_bag();
        void empty_bag();

        void set_active_piece();
        void place_active_piece();
        void remove_active_piece();

        bool translate_active_piece(int x, int y);
        bool rotate_active_piece(int direction);
        bool rotate_with_wall_kick(int direction);
        bool rotate_with_wall_kick(int x, int y, int direction);
        bool rotate_with_I_TYPE_wallkick_table(int direction);
        bool rotate_with_non_I_TYPE_wallkick_table(int direction);
};