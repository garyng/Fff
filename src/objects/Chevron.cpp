#include "pch.h"
#include "Chevron.h"

void Chevron::Render()
{
	Apply();

	glPushMatrix();
	{
		glTranslatef(0, 0.4, 0);
		One();
	}
	glPopMatrix();
	One();

}

void Chevron::One()
{
	glBegin(GL_QUADS);
	// front
	glColor3f(1, 1, 0);
	glVertex3f(-0.5f, 0, 0.05f);
	glVertex3f(0, 0.1f, 0.05f);
	glVertex3f(0.5f, 0, 0.05f);
	glColor3f(1, 1, 0.8);
	glVertex3f(0, 0.3f, 0);

	// back
	glColor3f(1, 1, 0);
	glVertex3f(-0.5f, 0, -0.05f);
	glColor3f(1, 1, 0.8);
	glVertex3f(0, 0.3f, 0);
	glColor3f(1, 1, 0);
	glVertex3f(0.5f, 0, -0.05f);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0.1f, -0.05f);

	glColor3f(1, 1, 0);
	// bottom view left
	glVertex3f(-0.5f, 0, -0.05f);
	glVertex3f(-0.5f, 0, 0.05f);
	glVertex3f(0, 0.1f, 0.05f);
	glVertex3f(0, 0.1f, -0.05f);

	// bottom view right
	glVertex3f(0, 0.1f, 0.05f);
	glVertex3f(0, 0.1f, -0.05f);
	glVertex3f(0.5f, 0, -0.05f);
	glVertex3f(0.5f, 0, 0.05f);

	glEnd();

	// left view
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0.8);
	glVertex3f(0, 0.3f, 0);
	glColor3f(1, 1, 0);
	glVertex3f(-0.5f, 0, -0.05f);
	glVertex3f(-0.5f, 0, 0.05f);

	// right view
	glColor3f(1, 1, 0.8);
	glVertex3f(0, 0.3f, 0);
	glColor3f(1, 1, 0);
	glVertex3f(0.5f, 0, -0.05f);
	glVertex3f(0.5f, 0, 0.05f);
	glEnd();

}
