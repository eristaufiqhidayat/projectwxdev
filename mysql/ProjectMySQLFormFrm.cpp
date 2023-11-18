///-----------------------------------------------------------------
///
/// @file      ProjectMySQLFormFrm.cpp
/// @author    eristaufiq
/// Created:   18/11/2023 08:42:52
/// @section   DESCRIPTION
///            ProjectMySQLFormFrm class implementation
///
///------------------------------------------------------------------

#include "ProjectMySQLFormFrm.h"
#include <mysql.h>
#include <mysqld_error.h>
char HOST[]="localhost";
char USER[]="root";
char PASS[]="";
char DB[]="kasir";
MYSQL *obj;
MYSQL *conection;
MYSQL_RES *result;
MYSQL_DATA data;
MYSQL_ROW row;
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// ProjectMySQLFormFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ProjectMySQLFormFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ProjectMySQLFormFrm::OnClose)
	EVT_ACTIVATE(ProjectMySQLFormFrm::ProjectMySQLFormFrmActivate)
	
	EVT_LIST_ITEM_SELECTED(ID_WXLISTCTRL1,ProjectMySQLFormFrm::WxListCtrl1Selected)
	EVT_BUTTON(ID_WXBUTTON1,ProjectMySQLFormFrm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

ProjectMySQLFormFrm::ProjectMySQLFormFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ProjectMySQLFormFrm::~ProjectMySQLFormFrm()
{
}

void ProjectMySQLFormFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("WxEdit1"), wxPoint(122, 181), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit1"));

	WxListCtrl1 = new wxListCtrl(this, ID_WXLISTCTRL1, wxPoint(21, 18), wxSize(921, 150), wxLC_REPORT | wxLC_ALIGN_LEFT, wxDefaultValidator, _("WxListCtrl1"));
	WxListCtrl1->InsertColumn(0, _("No"), wxLIST_FORMAT_LEFT, 29);
	WxListCtrl1->InsertColumn(1, _("Nama"), wxLIST_FORMAT_LEFT, 300);
	WxListCtrl1->InsertColumn(2, _("Password"), wxLIST_FORMAT_LEFT, 100);
	WxListCtrl1->SetBackgroundColour(wxColour(_("CYAN")));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("WxButton1"), wxPoint(207, 280), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	SetTitle(_("ProjectMySQLForm"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1010,428);
	Center();
	
	////GUI Items Creation End
}

void ProjectMySQLFormFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void ProjectMySQLFormFrm::WxButton1Click(wxCommandEvent& event)
{
	    //WxListCtrl1->InsertColumn(0,wxT("No"),wxLIST_FORMAT_LEFT,30);
	    //WxListCtrl1->InsertColumn(1,wxT("NAMA"),wxLIST_FORMAT_LEFT,200);
        obj = mysql_init(0);
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,"select * from pengguna order by id desc");
        result = mysql_use_result(obj);
        while(row = mysql_fetch_row(result)){
           //cout <<row<<endl; 
           WxListCtrl1->InsertItem(0,row[0]);
           WxListCtrl1->SetItem(0,1,row[1]);
           WxListCtrl1->SetItem(0,2,row[3]);
        }
        mysql_close(obj);
}

/*
 * ProjectMySQLFormFrmActivate
 */
void ProjectMySQLFormFrm::ProjectMySQLFormFrmActivate(wxActivateEvent& event)
{
	// insert your code here

}

/*
 * WxListCtrl1Selected
 */
void ProjectMySQLFormFrm::WxListCtrl1Selected(wxListEvent& event)
{
	long itemIndex = -1;
	while((itemIndex = WxListCtrl1->GetNextItem(itemIndex,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED)) != wxNOT_FOUND){
        WxEdit1->SetValue(WxListCtrl1->GetItemText(itemIndex,0));
    }
    // insert your code here
}
