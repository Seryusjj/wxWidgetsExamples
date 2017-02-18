#pragma once

#include <wx/glcanvas.h>

// the rendering context used by all GL canvases
class MyGlContext : public wxGLContext
{
public:
	MyGlContext(wxGLCanvas *canvas);

	// render the cube showing it at given angles
	void DrawRotatedCube(float xangle, float yangle);

private:
	// textures for the cube faces
	GLuint m_textures[6];
};