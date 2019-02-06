#include "pch.h"
#include "IceCream.h"

void IceCream::Render()
{
	Apply();

	GLUquadricObj* pObj = gluNewQuadric();

	glPushMatrix();
	glColor3f(0.87f, 0.72f, 0.53f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 1.0f);
	gluCylinder(pObj, 0.0f, 7.0f, 25.0f, 20, 72);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	glTranslatef(0.0f, 30.0f, 0.0f);
	//glRotatef(90.0f, 1.0f, 0.0f, 1.0f);
	gluSphere(pObj, 10.0f, 24, 12);
	glPopMatrix();

	glEnd();
	gluDeleteQuadric(pObj);

}
