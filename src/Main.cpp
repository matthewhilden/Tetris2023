// This File maintains the implementation for the TetrisApp class
// The TetrisApp defines the entry point for the Application and launches the program/GUI.

#include <wx/wx.h>
#include <wx/wxprec.h>

#include "Board.h"
#include "GameBoardFrame.h"
 
class TetrisApp : public wxApp
{
    public:

        virtual bool OnInit();

    private:
};
 
wxIMPLEMENT_APP(TetrisApp);

wxBEGIN_EVENT_TABLE(GameBoardFrame, wxFrame)
    EVT_PAINT(GameBoardFrame::OnPaint)
wxEND_EVENT_TABLE()

bool TetrisApp::OnInit()
{
    GameBoardFrame * topLevelFrame = new GameBoardFrame();
    return true;
}