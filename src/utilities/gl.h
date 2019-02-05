#pragma once
#include <GL/glut.h>
#include <string>

inline void glutStrokeString(std::string string)
{
	glutStrokeString(GLUT_STROKE_MONO_ROMAN, (unsigned char*)string.c_str());
}