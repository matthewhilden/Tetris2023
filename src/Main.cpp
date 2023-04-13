// This File maintains the implementation for the TetrisApp class
// The TetrisApp defines the entry point for the Application and launches the program/GUI.

#include "GameBoardPanel.h"
 
class TetrisApp : public wxApp
{
    public:

        virtual bool OnInit();
    
    private:

        GameBoardPanel * topLevelFrame;
};
 
wxIMPLEMENT_APP(TetrisApp);
 
bool TetrisApp::OnInit()
{
    // ** PROBABLY WANT TO MOVE SIZER INTO TETRISFRAME CLASS AND ORGANIZE INSIDE THERE **

    topLevelFrame = new GameBoardPanel();
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

/*
    // add the TetrisFrame instance to the sizer
    // ** I THINK THIS IS WHERE WE ADD DIFFERENT PANEL TYPES **
    sizer->Add(frame, 1, wxEXPAND | wxALL, 0);
*/
    topLevelFrame->SetSizer(sizer);

    topLevelFrame->Show(true);

    return true;
}