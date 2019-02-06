#include "pch.h"
#include "Pizza.h"

void Pizza::Render()
{
	Apply();

	glPushMatrix();
	glTranslatef(-10.0f, 12.0f, -0.8f);
	Draw();
	glPopMatrix();

	//float ylength = (24);
	//float xlength = (24);
	//float zlength = 2.0;
}

void Pizza::Draw()
{
	GLUquadricObj* pObj = gluNewQuadric();

	//pizza base outer
	glPushMatrix();
	glColor3f(0.4f, 0.2f, 0.0f);
	glTranslatef(10.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 12.0f, 12.0f, 1.5f, 24, 72);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6f, 0.4f, 0.0f);
	glTranslatef(10.0f, 0.0f, 0.0f);
	gluDisk(pObj, 0.0f, 12.0f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6f, 0.4f, 0.0f);
	glTranslatef(10.0f, 0.0f, 1.5f);
	gluDisk(pObj, 0.0f, 12.0f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.0f);
	glTranslatef(10.0f, 0.0f, 1.6f);
	gluDisk(pObj, 0.0f, 10.0f, 26, 13);
	glPopMatrix();

	//topping
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(4.5f, 2.5f, 1.7f);
	gluDisk(pObj, 0.0f, 2.0f, 26, 13);
	glPopMatrix();

	//topping
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(9.0f, -2.5f, 1.7f);
	gluDisk(pObj, 0.0f, 1.5f, 26, 13);
	glPopMatrix();

	//topping
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(14.0f, 6.0f, 1.7f);
	gluDisk(pObj, 0.0f, 2.0f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(15.0f, -4.0f, 1.7f);
	gluDisk(pObj, 0.0f, 1.5f, 26, 13);
	glPopMatrix();

	//topping
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(10.0f, -7.0f, 1.7f);
	gluDisk(pObj, 0.0f, 2.0f, 26, 13);
	glPopMatrix();

	//topping
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(4.0f, -3.0f, 1.7f);
	gluDisk(pObj, 0.0f, 2.0f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(9.0f, 7.0f, 1.7f);
	gluDisk(pObj, 0.0f, 1.5f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(11.0f, 2.0f, 1.7f);
	gluDisk(pObj, 0.0f, 2.0f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(17.0f, 1.0f, 1.7f);
	gluDisk(pObj, 0.0f, 1.5f, 26, 13);
	glPopMatrix();

	gluDeleteQuadric(pObj);
}
