// This File maintains the header for the GameBoardPanel class object
// A GameBoardPanel maintains the panel of the GUI responsible for displaying the current game and board state

#pragma once

#include <wx/wx.h>
#include <wx/wxprec.h>

#include "Board.h"

//const int KEY_CODE_ROTATE_CW = ??
//const int KEY_CODE_ROTATE_CCW = ??

const int FRAME_X_OFFSET = 500;
const int FRAME_Y_OFFSET = 25;

const int FRAME_WIDTH = 1000;
const int FRAME_HEIGHT = 1000;

const int PANEL_BOARD_HEIGHT = 800;
const int PANEL_BOARD_WIDTH = PANEL_BOARD_HEIGHT / 2;

const int PANEL_BOARD_CELL_HEIGHT = PANEL_BOARD_HEIGHT / BOARD_HEIGHT;
const int PANEL_BOARD_CELL_WIDTH = PANEL_BOARD_WIDTH / BOARD_WIDTH;

const int PANEL_BOARD_X_OFFSET = (FRAME_WIDTH / 2) - (PANEL_BOARD_WIDTH);
const int PANEL_BOARD_Y_OFFSET = (FRAME_HEIGHT / 2) - (PANEL_BOARD_HEIGHT);

class GameBoardPanel: public wxPanel
{
    public:

        GameBoardPanel();

        DECLARE_EVENT_TABLE();

    private:

        Board game_board;
        //Tetromino * active_piece;

        void OnPaint(wxPaintEvent & event);
};