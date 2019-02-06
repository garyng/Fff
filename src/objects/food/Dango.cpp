#include "pch.h"
#include "Dango.h"

void Dango::Render()
{
	Apply();

	GLUquadricObj* pObj = gluNewQuadric();

	glPushMatrix();
	glTranslatef(0, _height / 2.0f, 0);
	glRotatef(_angle, 0, 0, 1);
	glRotatef(-90, 0, 1, 0);
	// move the entire thing to the center
	glTranslatef(0.0f, 0.0f, -_stickLength / 2.0f);

	// stick
	glColor3f(0.55f, 0.27f, 0.1f);
	gluCylinder(pObj, 0.5f, 0.5f, _stickLength, 24, 72);

	// pink
	gluSphere(pObj, _ballRadius, 24, 12);

	// yellow
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0, 0, 2 * _ballRadius);
	gluSphere(pObj, _ballRadius, 24, 12);

	// purple
	glColor3f(0.87f, 0.63f, 0.87f);
	glTranslatef(0, 0, 2 * _ballRadius);
	gluSphere(pObj, _ballRadius, 24, 12);

	glPopMatrix();


	//float ylength = (stickLength + ballRadius) * sin(toRadians(angle));
	//float xlength = (stickLength + ballRadius) * cos(toRadians(angle));
	//float zlength = ballRadius * 2;
	//drawBoundingBox(xlength, ylength, zlength);
}
