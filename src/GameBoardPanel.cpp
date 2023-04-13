// This class maintains the implementation for the GameBoardPanel class contained in the GameBoardPanel class header file

#include "GameBoardPanel.h"

GameBoardPanel::GameBoardPanel()
{
    SetSize(FRAME_X_OFFSET, FRAME_Y_OFFSET, FRAME_WIDTH, FRAME_HEIGHT, wxSIZE_AUTO);
    Show(true);
}

void GameBoardPanel::OnPaint(wxPaintEvent & event)
{
    wxPaintDC dc(this);
}