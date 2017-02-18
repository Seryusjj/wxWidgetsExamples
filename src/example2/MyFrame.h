#pragma once

#include <wx/wx.h>

// Define a new frame type
class MyFrame : public wxFrame
{
public:
	MyFrame(bool stereoWindow = false);

protected:
	enum
	{
		NEW_STEREO_WINDOW = wxID_HIGHEST + 1
	};

private:
	void OnClose(wxCommandEvent& event);
	void OnNewWindow(wxCommandEvent& event);
	void OnNewStereoWindow(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};