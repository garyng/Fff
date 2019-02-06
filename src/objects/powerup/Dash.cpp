﻿#include "pch.h"
#include "Dash.h"

void Dash::Render()
{
	Apply();
	glPushMatrix();
	{
		glColor3f(0.682f, 0.776f, 0.812f);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(8, 5, 64, 64);
	}
	glPopMatrix();
	Draw();
}

void Dash::First()
{
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(4.0, 6.0, 50, 10);
	glPopMatrix();
}

void Dash::Second()
{
	GLUquadricObj* qObj = gluNewQuadric();
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(qObj, 4, 4, 18, 50, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(qObj, 3, 4, 1, 50, 10);
	glColor3f(0.7, 0, 0);
	gluDisk(qObj, 0, 3, 50, 10);
	glPopMatrix();
}

void Dash::Third()
{
	GLUquadricObj* qObj = gluNewQuadric();
	glPushMatrix();
	glColor3f(0.8f, 0.8f, 0.8f); // silver
	glTranslatef(0, 0, 0);
	gluCylinder(qObj, 2, 1, 2, 25, 5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3f, 0.3f, 1.0f);
	glTranslatef(0, 0, 2);
	gluDisk(qObj, 0, 1, 25, 5);
	glPopMatrix();
}

void Dash::Forth()
{
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(-9.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 4.0f, 0.0f);
	glVertex3f(-4.0f, 9.0f, 0.0f);
	glVertex3f(-8.0f, 6.0f, 0.0f);
	glEnd();
}

void Dash::Draw()
{
	glPushMatrix();
	glTranslatef(0, 22, 0);
	First();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0);
	Second();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 15, 2.5);
	Third();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	for (int i = 0; i < 3; i++)
	{
		glRotatef(120, 0, 1, 0);
		Forth();
	}
	glPopMatrix();
}
