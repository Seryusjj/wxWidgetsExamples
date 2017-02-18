#include <wx/wx.h>
#include "MyFrame.h"
// Define a new application type
class MyApp : public wxApp
{
public:
	MyApp() {}

	// virtual wxApp methods
	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;
};

// Implements MyApp& GetApp()
DECLARE_APP(MyApp)
// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	new MyFrame();

	return true;
}

int MyApp::OnExit()
{
	return wxApp::OnExit();
}