///-----------------------------------------------------------------
///
/// @file      Untitled1Frm.cpp
/// @author    eristaufiq
/// Created:   20/11/2023 07:36:13
/// @section   DESCRIPTION
///            Untitled1Frm class implementation
///
///------------------------------------------------------------------

#include "Untitled1Frm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Untitled1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Untitled1Frm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Untitled1Frm::OnClose)
END_EVENT_TABLE()
////Event Table End

Untitled1Frm::Untitled1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Untitled1Frm::~Untitled1Frm()
{
}

void Untitled1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(_("EntriData"));
	SetIcon(wxNullIcon);
	SetSize(8,8,841,477);
	Center();
	
	////GUI Items Creation End
}

void Untitled1Frm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
