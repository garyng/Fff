#include "pch.h"
#include "utilities/gl.h"
#include "StartScreen.h"

void StartScreen::Render()
{
	if (_gameService->TotalTimeElapsed() - _sinceLastVisibilityToggle > 0.5)
	{
		_visible = !_visible;
		_sinceLastVisibilityToggle = _gameService->TotalTimeElapsed();
	}
	if (!_visible) return;

	Apply();
	glPushAttrib(GL_LINE_BIT);
	glPushMatrix();
	{
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glScalef(0.05f, 0.05f, 0.05f);
		glutStrokeString("Press <space> to start game");
	}
	glPopMatrix();
	glPopAttrib();

}
