#include "pch.h"
#include "utilities/gl.h"
#include "Countdown.h"
#include <boost/format.hpp>

void Countdown::Render()
{
	Apply();
	int mins = _gameService->TimeLeft() / 60;
	int seconds = _gameService->TimeLeft() % 60;
	std::string left = (boost::format("%02i:%02i") % mins % seconds).str();
	glPushAttrib(GL_LINE_BIT);
	glPushMatrix();
	{
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glScalef(0.05f, 0.05f, 0.05f);
		glutStrokeString(left);
	}
	glPopMatrix();
	glPopAttrib();
}