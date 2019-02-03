#include "pch.h"
#include "Player1.h"

void Player1::Animate()
{
	_left.x += _left.y * _elapsed;

	//_logger->Debug("left: [%1%, %2%, %3%, %4%]", {
	//	std::to_string(_left.x), std::to_string(_left.y), std::to_string(_left.z), std::to_string(_left.a)
	//});

	Wrap(_left.x, _left.y, _left.z, _left.a, WrappingBehaviour::Bounce);
	//_logger->Debug("left wrapped: [%1%, %2%, %3%, %4%]", {
	//	std::to_string(_left.x), std::to_string(_left.y), std::to_string(_left.z), std::to_string(_left.a)
	//});

	_right.x += _right.y * _elapsed;

	//_logger->Debug("right: [%1%, %2%, %3%, %4%]", {
	//	std::to_string(_right.x), std::to_string(_right.y), std::to_string(_right.z), std::to_string(_right.a)
	//});
	Wrap(_right.x, _right.y, _right.z, _right.a, WrappingBehaviour::Bounce);
	/*_logger->Debug("right wrapped: [%1%, %2%, %3%, %4%]", {
		std::to_string(_right.x), std::to_string(_right.y), std::to_string(_right.z), std::to_string(_right.a)
	});*/
}

void Player1::Render()
{
	Apply();
	Animate();
	OrientDirection();

	glPushMatrix();
	glTranslatef(0.0f, 21.0f, 0.0f);
	Head();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 12.0f, 0.0f);
	Body();
	glPopMatrix();
	//right hand
	glPushMatrix();
	glTranslatef(5.5f, 16.5f, -0.5f);
	glRotatef(_right.x, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -5.0f, 0.0f);
	Hand();
	glPopMatrix();
	//left hand
	glPushMatrix();
	glTranslatef(-5.5f, 16.5f, -0.5f);
	glRotatef(_left.x, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -5.0f, 0.0f);
	Hand();
	glPopMatrix();
	//right leg
	glPushMatrix();
	glTranslatef(2.0f, 8.5f, 0.0f);
	glRotatef(_left.x, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -5.0f, 0.0f);
	Leg();
	glPopMatrix();
	//left leg
	glPushMatrix();
	glTranslatef(-2.0f, 8.5f, 0.0f);
	glRotatef(_right.x, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -5.0f, 0.0f);
	Leg();
	glPopMatrix();
}


void Player1::Eye()
{
	glPushMatrix();
	glTranslatef(-3.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);

	glTranslatef(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);

	glTranslatef(1.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Player1::Nose()
{
	glPushMatrix();
	glColor3f(0.62f, 0.36f, 0.20f);
	glTranslatef(-1.0f, 0.0f, 0.0f);
	glRectf(2.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Player1::Mouth()
{
	glPushMatrix();
	glColor3f(0.29f, 0.15f, 0.05f);
	glTranslatef(-2.0f, 0.0f, 0.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(3.0f, 0.0f, 0.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(-3.0f, -1.0f, 0.0f);
	glRectf(4.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Player1::Hair()
{
	glColor3f(0.29f, 0.15f, 0.05f);
	//top hair
	glPushMatrix();
	glColor3f(0.29f, 0.15f, 0.05f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glTranslatef(-4.0f, -4.0f, -4.001f);
	glRectf(8.0f, 8.0f, 0.0f, 0.0f);
	glPopMatrix();
	//back hair
	glPushMatrix();
	glColor3f(0.29f, 0.15f, 0.05f);
	glTranslatef(-4.0f, -4.0f, -4.01f);
	glRectf(8.0f, 8.0f, 0.0f, 0.0f);
	glPopMatrix();
	//front hair
	glPushMatrix();
	glTranslatef(-4.0f, 3.01f, 4.01f);
	glRectf(8.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glRectf(8.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(7.0f, 0.0f, 0.0f);
	glRectf(1.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();
	//left hair
	glPushMatrix();
	glTranslatef(-4.01f, -1.0f, 4.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRectf(1.0f, 5.0f, 0.0f, 0.0f);
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRectf(2.0f, 4.0f, 0.0f, 0.0f);
	glTranslatef(2.0f, -2.0f, 0.0f);
	glRectf(2.0f, 6.0f, 0.0f, 0.0f);
	glTranslatef(2.0f, -1.0f, 0.0f);
	glRectf(2.0f, 7.0f, 0.0f, 0.0f);
	glTranslatef(2.0f, -1.0f, 0.0f);
	glRectf(1.0f, 8.0f, 0.0f, 0.0f);
	glPopMatrix();
	//right hair
	glPushMatrix();
	glTranslatef(4.01f, -1.0f, 4.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRectf(1.0f, 5.0f, 0.0f, 0.0f);
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRectf(2.0f, 4.0f, 0.0f, 0.0f);
	glTranslatef(2.0f, -2.0f, 0.0f);
	glRectf(2.0f, 6.0f, 0.0f, 0.0f);
	glTranslatef(2.0f, -1.0f, 0.0f);
	glRectf(2.0f, 7.0f, 0.0f, 0.0f);
	glTranslatef(2.0f, -1.0f, 0.0f);
	glRectf(1.0f, 8.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Player1::Face()
{
	glTranslatef(0.0f, 1.0f, 0.0f);
	Eye();
	glTranslatef(0.0f, -1.0f, 0.0f);
	Nose();
	glTranslatef(0.0f, -1.0f, 0.0f);
	Mouth();
}

void Player1::Head()
{
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(1.0f, 0.91f, 0.67f);
	//glScalef(1.0f,1.0f,1.0f);
	glutSolidCube(8);
	glPopAttrib();
	glPopMatrix();

	Hair();
	glTranslatef(0.0f, -2.0f, 4.01f);
	Face();
}

void Player1::Body()
{
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(0.08f, 0.74f, 0.72f);
	glScalef(8.0f, 10.0f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();
}

void Player1::Hand()
{
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(0.08f, 0.74f, 0.72f);
	glTranslatef(0.0, 4.0f, 0.0f);
	glutSolidCube(3);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0f, 0.91f, 0.67f);
	glTranslatef(0.0, -1.0f, 0.0f);
	glScalef(3.0f, 7.0f, 3.0f);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();
}

void Player1::Leg()
{
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(0.04f, 0.43f, 0.67f);

	glTranslatef(0.0, 0.5f, 0.0f);
	glScalef(4.0f, 6.0f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.08f, 0.74f, 0.72f);
	glTranslatef(0.0, -3.0f, 0.0f);
	glScalef(4.0f, 1.0f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();
}
