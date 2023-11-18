//---------------------------------------------------------------------------
//
// Name:        ProjectMySQLFormApp.cpp
// Author:      eristaufiq
// Created:     18/11/2023 08:42:51
// Description: 
//
//---------------------------------------------------------------------------

#include "ProjectMySQLFormApp.h"
#include "ProjectMySQLFormFrm.h"
#include <mysql.h>
#include <mysqld_error.h>




IMPLEMENT_APP(ProjectMySQLFormFrmApp)

bool ProjectMySQLFormFrmApp::OnInit()
{
    ProjectMySQLFormFrm* frame = new ProjectMySQLFormFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int ProjectMySQLFormFrmApp::OnExit()
{
	return 0;
}
