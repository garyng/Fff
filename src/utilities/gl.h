#pragma once
#include <GL/glut.h>
#include <string>

inline void glutStrokeString(std::string string)
{
	glutStrokeString(GLUT_STROKE_MONO_ROMAN, (unsigned char*)string.c_str());
}

inline void glutBitmapString(Vector2<int> topLeft, std::string string)
{
	glPushMatrix();
	{
		glRasterPos2i(topLeft.x, topLeft.y);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24 , (unsigned char*)string.c_str());
	}
	glPopMatrix();
}