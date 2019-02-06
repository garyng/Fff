#include "pch.h"
#include "Thunder.h"

void Thunder::Render()
{
	Apply();

	GLUquadricObj* pObj = gluNewQuadric();

	glPushMatrix();
	{
		glColor3f(0.682f, 0.776f, 0.812f);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(24, 5, 64, 64);
	}
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(1.0f, 15.0f, 1.0f);
	gluSphere(pObj, 7.0f, 24, 12);

	glTranslatef(6.0f, 0.0f, 0.0f);
	gluSphere(pObj, 6.0f, 24, 12);

	glTranslatef(-14.0f, 0.0f, 0.0f);
	gluSphere(pObj, 6.0f, 24, 12);

	glTranslatef(-5.0f, 0.0f, 0.0f);
	gluSphere(pObj, 4.0f, 24, 12);

	glTranslatef(26.0f, 0.0f, 0.0f);
	gluSphere(pObj, 4.0f, 24, 12);

	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 15.0f, 1.0f);
	glRotatef(110.0f, 0.0f, 1.0f, 1.0f);
	gluCylinder(pObj, 5.0f, 0.0f, 20.0f, 20, 72);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 15.0f, 1.0f);
	glRotatef(250.0f, 0.0f, 20.0f, -10.0f);
	gluCylinder(pObj, 5.0f, 0.0f, 25.0f, 20, 72);
	glPopMatrix();

	glEnd();
	gluDeleteQuadric(pObj);

	/*float ylength = (25 + 4) * sin(2.18);
	float xlength = (25 + 4) * cos(2.18);
	float zlength = 4 * 2;
	drawBoundingBox(39, 29, 16);*/
}
