///-----------------------------------------------------------------
///
/// @file      ProjectMySQLFormFrm.h
/// @author    eristaufiq
/// Created:   18/11/2023 08:42:52
/// @section   DESCRIPTION
///            ProjectMySQLFormFrm class declaration
///
///------------------------------------------------------------------

#ifndef __PROJECTMYSQLFORMFRM_H__
#define __PROJECTMYSQLFORMFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/tglbtn.h>
#include <wx/textctrl.h>
#include <wx/listctrl.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef ProjectMySQLFormFrm_STYLE
#define ProjectMySQLFormFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class ProjectMySQLFormFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ProjectMySQLFormFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("ProjectMySQLForm"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ProjectMySQLFormFrm_STYLE);
		virtual ~ProjectMySQLFormFrm();
		void WxButton1Click(wxCommandEvent& event);
		void ProjectMySQLFormFrmActivate(wxActivateEvent& event);
		void WxListCtrl1Selected(wxListEvent& event);
		void WxToggleButton1Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton4;
		wxButton *WxButton3;
		wxTextCtrl *WxEdit3;
		wxButton *WxButton2;
		wxTextCtrl *WxEdit2;
		wxToggleButton *WxToggleButton1;
		wxTextCtrl *WxEdit1;
		wxListCtrl *WxListCtrl1;
		wxButton *WxButton1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON4 = 1013,
			ID_WXBUTTON3 = 1012,
			ID_WXEDIT3 = 1011,
			ID_WXBUTTON2 = 1010,
			ID_WXEDIT2 = 1009,
			ID_WXTOGGLEBUTTON1 = 1008,
			ID_WXEDIT1 = 1004,
			ID_WXLISTCTRL1 = 1003,
			ID_WXBUTTON1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void ListGrid();
};

#endif
