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
#include "Untitled1Frm.h";


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
	EVT_BUTTON(ID_WXBUTTON4,ProjectMySQLFormFrm::WxButton4Click)
	EVT_BUTTON(ID_WXBUTTON3,ProjectMySQLFormFrm::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON2,ProjectMySQLFormFrm::WxButton2Click)
	EVT_TOGGLEBUTTON(ID_WXTOGGLEBUTTON1,ProjectMySQLFormFrm::WxToggleButton1Click)
	
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
int tambahdata(wxString nama,wxString alamat){
    
        wxString sql = "insert `toko` (`nama`, `alamat`) values('"+nama+"','"+alamat+"')";
        obj = mysql_init(0);
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,sql);
        result = mysql_use_result(obj);
        mysql_close(obj); 
}
int editdata(wxString nama,wxString alamat,wxString id){
    
        wxString sql = "UPDATE `toko` SET `nama` = '"+nama+"', `alamat` = '"+alamat+"' WHERE `toko`.`id` ="+id ;
        obj = mysql_init(0);
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,sql);
        result = mysql_use_result(obj);
        mysql_close(obj); 
}
int deletedata(wxString id){
    
        wxString sql = "DELETE from `toko`  WHERE `toko`.`id` ="+id ;
        //wxMessageBox(sql,"Pesan");
        obj = mysql_init(0);
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,sql);
        result = mysql_use_result(obj);
        mysql_close(obj); 
}
void ProjectMySQLFormFrm::ListGrid(){
        WxListCtrl1->ClearAll();
        WxListCtrl1->InsertColumn(0,wxT("ID"),wxLIST_FORMAT_CENTER,50);
	    WxListCtrl1->InsertColumn(1,wxT("NAMA"),wxLIST_FORMAT_LEFT,200);
	    WxListCtrl1->InsertColumn(2,wxT("ALAMAT"),wxLIST_FORMAT_LEFT,300);
	    
        obj = mysql_init(0);
        //wxMessageBox(&obj,"pesan");
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,"select * from toko order by id desc");
        result = mysql_use_result(obj);
        while(row = mysql_fetch_row(result)){
           //cout <<row<<endl; 
           WxListCtrl1->InsertItem(0,row[0]);
           WxListCtrl1->SetItem(0,1,row[1]);
           WxListCtrl1->SetItem(0,2,row[2]);
        }
        mysql_close(obj);  
}
void ProjectMySQLFormFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxButton4 = new wxButton(this, ID_WXBUTTON4, _("WxButton4"), wxPoint(90, 266), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton4"));

	WxButton3 = new wxButton(this, ID_WXBUTTON3, _("Delete"), wxPoint(762, 262), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton3"));
	WxButton3->SetBackgroundColour(wxColour(_("RED")));

	WxEdit3 = new wxTextCtrl(this, ID_WXEDIT3, _("WxEdit3"), wxPoint(355, 263), wxSize(262, 19), 0, wxDefaultValidator, _("WxEdit3"));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("Update"), wxPoint(764, 231), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->SetBackgroundColour(wxColour(_("BLUE")));

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("WxEdit2"), wxPoint(354, 230), wxSize(262, 19), 0, wxDefaultValidator, _("WxEdit2"));

	WxToggleButton1 = new wxToggleButton(this, ID_WXTOGGLEBUTTON1, _("Close"), wxPoint(763, 297), wxSize(74, 25), 0, wxDefaultValidator, _("WxToggleButton1"));
	WxToggleButton1->SetBackgroundColour(wxColour(_("RED")));

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("WxEdit1"), wxPoint(354, 199), wxSize(263, 19), 0, wxDefaultValidator, _("WxEdit1"));

	WxListCtrl1 = new wxListCtrl(this, ID_WXLISTCTRL1, wxPoint(16, 18), wxSize(883, 150), wxLC_REPORT | wxLC_ALIGN_LEFT, wxDefaultValidator, _("WxListCtrl1"));
	WxListCtrl1->InsertColumn(0, _("No"), wxLIST_FORMAT_LEFT, 29);
	WxListCtrl1->InsertColumn(1, _("Nama"), wxLIST_FORMAT_LEFT, 300);
	WxListCtrl1->InsertColumn(2, _("Alamat"), wxLIST_FORMAT_LEFT, 300);
	WxListCtrl1->SetBackgroundColour(wxColour(_("CYAN")));

	/* Untuk Menambah Data
	*/
	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Tambah"), wxPoint(764, 197), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxButton1->SetBackgroundColour(wxColour(_("GREEN")));

	SetTitle(_("Applikasi Alamat"));
	SetIcon(wxNullIcon);
	SetSize(8,8,932,539);
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
   tambahdata(WxEdit1->GetValue(),WxEdit2->GetValue());
   ListGrid();
}
/*
 * ProjectMySQLFormFrmActivate
 */
void ProjectMySQLFormFrm::ProjectMySQLFormFrmActivate(wxActivateEvent& event)
{
   ListGrid();
}

/*
 * WxListCtrl1Selected
 */
void ProjectMySQLFormFrm::WxListCtrl1Selected(wxListEvent& event)
{

    long itemIndex = -1;
	while((itemIndex = WxListCtrl1->GetNextItem(itemIndex,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED)) != wxNOT_FOUND){
        WxEdit1->SetValue(WxListCtrl1->GetItemText(itemIndex,1));
        WxEdit2->SetValue(WxListCtrl1->GetItemText(itemIndex,2));
        WxEdit3->SetValue(WxListCtrl1->GetItemText(itemIndex,0));
    }
    // insert your code here
}

/*
 * WxToggleButton1Click
 */
void ProjectMySQLFormFrm::WxToggleButton1Click(wxCommandEvent& event)
{
	// insert your code here
	Destroy();
}

/*
 * WxButton2Click
 */
void ProjectMySQLFormFrm::WxButton2Click(wxCommandEvent& event)
{
	// insert your code here
	editdata(WxEdit1->GetValue(),WxEdit2->GetValue(),WxEdit3->GetValue());
	wxMessageBox("Sukses di Update","Pesan");
    ListGrid();
}

/*
 * WxButton3Click
 */
void ProjectMySQLFormFrm::WxButton3Click(wxCommandEvent& event)
{
      wxMessageDialog *dial = new wxMessageDialog(NULL,wxT("Are you sure to quit?"), wxT("Question"),wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
       if(dial->ShowModal() == wxID_YES){
            deletedata(WxEdit3->GetValue());
            wxMessageBox("Delete oK","Pesan");
        }else{
           wxMessageBox("Batal Delete","Pesan"); 
        }
      ListGrid();
}

/*
 * WxButton4Click
 */
void ProjectMySQLFormFrm::WxButton4Click(wxCommandEvent& event)
{
	// insert your code here
	Untitled1Frm* Frame = new Untitled1Frm(NULL);
	Frame->Show(TRUE);
}
