// This File maintains the header for the GameBoardPanel class object

#pragma once

#include <wx/wx.h>
#include <wx/wxprec.h>

#include "Board.h"

//const int KEY_CODE_ROTATE_CW = ??
//const int KEY_CODE_ROTATE_CCW = ??

const bool GAME_BOARD_SPAWN = true;

const wxColour ORANGE = wxColor(255, 165, 0);
const wxColour PURPLE = wxColour(128, 0, 128);

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

class GameBoardFrame : public wxFrame
{
    public:

        GameBoardFrame();

        DECLARE_EVENT_TABLE();

    private:

        bool visibleSpawn;
        Board gameBoard;

        void OnPaint(wxPaintEvent & event);
};