#include "pch.h"
#include "Player.h"

void Player::Render()
{
	// todo: only self animations use delta, in this case if the player has it own animation, it should store them in other places
	// todo: aggregate all transformtion into one?
	ApplyDeltas();
	Wrap();
	Transform();
	glPushMatrix();
	{
		glScalef(0.01f, 0.01f, 0.01f);
		glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)nameof(*this).c_str());
	}
}
