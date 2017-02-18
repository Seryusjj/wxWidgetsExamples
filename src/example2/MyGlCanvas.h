#pragma once

#include <wx/glcanvas.h>
#include <wx/wx.h>
#include "MyGlContext.h"

class MyGlCanvas : public wxGLCanvas
{
public:
	MyGlCanvas(wxWindow *parent, int *attribList = NULL);
protected:
	// control ids
	enum
	{
		SpinTimer = wxID_HIGHEST + 1
	};
private:
	MyGlContext* m_context;

	void OnPaint(wxPaintEvent& event);
	void Spin(float xSpin, float ySpin);
	void OnKeyDown(wxKeyEvent& event);
	void OnSpinTimer(wxTimerEvent& WXUNUSED(event));

	// angles of rotation around x- and y- axis
	float m_xangle, m_yangle;

	wxTimer m_spinTimer;
	bool m_useStereo, m_stereoWarningAlreadyDisplayed;

	wxDECLARE_EVENT_TABLE();
};