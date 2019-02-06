#include "pch.h"
#include "utilities/gl.h"
#include "EndScreen.h"

void EndScreen::Render()
{

	if (_gameService->TotalTimeElapsed() - _sinceLastVisibilityToggle > 0.5)
	{
		_visible = !_visible;
		_sinceLastVisibilityToggle = _gameService->TotalTimeElapsed();
	}
	if (!_visible) return;

	bool isTie = false;
	std::shared_ptr<Player> winner = _gameService->Winner(isTie);
	std::string text = isTie ? "It's a tie!" : nameof(*winner) + " is the winner!";

	Apply();
	glPushAttrib(GL_LINE_BIT);
	glPushMatrix();
	{
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glScalef(0.05f, 0.05f, 0.05f);
		glutStrokeString(text);
	}
	glPopMatrix();
	glPopAttrib();
}
