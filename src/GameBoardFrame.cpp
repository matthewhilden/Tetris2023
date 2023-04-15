// This class maintains the implementation for the GameBoardPanel class contained in the GameBoardPanel class header file

#include "GameBoardFrame.h"

GameBoardFrame::GameBoardFrame() : wxFrame(nullptr, wxID_ANY, "Tetris")
{
    SetSize(FRAME_X_OFFSET, FRAME_Y_OFFSET, FRAME_WIDTH, FRAME_HEIGHT, wxSIZE_AUTO);
    Show(true);
}

void GameBoardFrame::OnPaint(wxPaintEvent & event)
{
    
}