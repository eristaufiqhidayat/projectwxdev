//---------------------------------------------------------------------------
//
// Name:        ProjectMySQLFormApp.h
// Author:      eristaufiq
// Created:     18/11/2023 08:42:51
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROJECTMYSQLFORMFRMApp_h__
#define __PROJECTMYSQLFORMFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class ProjectMySQLFormFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
