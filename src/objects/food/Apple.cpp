#include "pch.h"
#include "Apple.h"

void Apple::Render()
{
	Apply();
	Body();
	Leaf();
}

void Apple::Body()
{
	GLUquadricObj* pObj = gluNewQuadric();

	glPushMatrix(); //apple
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 4.0f, 0.0f);
	gluSphere(pObj, 4.0f, 24, 12);
	glPopMatrix();

	glPushMatrix(); //apple stick
	glColor3f(0.55f, 0.27f, 0.1f);
	glTranslatef(0.0f, 11.0f, 0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 0.8f, 0.5f, 4.0f, 24, 72);
	glPopMatrix();

	// drawBoundingBox(7.0, 10.0, 7.0);
}

void Apple::Leaf()
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.0, 4.5);
	glVertex2f(0.0, 4.5);
	glVertex2f(4.0, 9.5);
	glVertex2f(0.0, 8.0);
	glEnd();
}
