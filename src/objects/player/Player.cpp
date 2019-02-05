#include "pch.h"
#include "Player.h"

void Player::OrientDirection()
{
	float angle = std::acos(_direction.z /
		std::sqrt((_direction.x * _direction.x + _direction.z * _direction.z))) * 180.0 / PI;
	angle = angle * (_direction.x == -1 ? -1 : 1);
	glRotatef(angle, 0, 1, 0);
	// _logger->Debug("%1% direction: %2% degree", {nameof(*this), std::to_string(angle)});
}

bool Player::HasPositionChanged()
{
	bool changed = (_lastPosition.x - _position.x != 0) ||
		(_lastPosition.y - _position.y != 0) ||
		(_lastPosition.z - _position.z != 0);

	_lastPosition = _position;
	return changed;
}

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
	glPopMatrix();
}
