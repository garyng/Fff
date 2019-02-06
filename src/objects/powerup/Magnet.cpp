#include "pch.h"
#include "Magnet.h"

void Magnet::Render()
{
	Apply();

	glPushMatrix();
	{
		glColor3f(0.682f, 0.776f, 0.812f);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(15, 5, 64, 64);
	}
	glPopMatrix();

	glTranslatef(0, 5, 0);

	glBegin(GL_QUADS);

	//front blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(5.0f, 3.0f, 2.0f);
	glVertex3f(5.0f, 0.0f, 2.0f);
	glVertex3f(8.0f, 0.0f, 2.0f);
	glVertex3f(8.0f, 3.0f, 2.0f);

	//back blue
	glVertex3f(5.0f, 3.0f, -2.0f);
	glVertex3f(5.0f, 0.0f, -2.0f);
	glVertex3f(8.0f, 0.0f, -2.0f);
	glVertex3f(8.0f, 3.0f, -2.0f);

	//left blue
	glVertex3f(5.0f, 3.0f, 2.0f);
	glVertex3f(5.0f, 0.0f, 2.0f);
	glVertex3f(5.0f, 0.0f, -2.0f);
	glVertex3f(5.0f, 3.0f, -2.0f);

	//right blue
	glVertex3f(8.0f, 3.0f, 2.0f);
	glVertex3f(8.0f, 0.0f, 2.0f);
	glVertex3f(8.0f, 0.0f, -2.0f);
	glVertex3f(8.0f, 3.0f, -2.0f);

	//top blue
	glVertex3f(5.0f, 3.0f, -2.0f);
	glVertex3f(5.0f, 3.0f, 2.0f);
	glVertex3f(8.0f, 3.0f, 2.0f);
	glVertex3f(8.0f, 3.0f, -2.0f);

	//bottom blue
	glVertex3f(5.0f, 0.0f, -2.0f);
	glVertex3f(5.0f, 0.0f, 2.0f);
	glVertex3f(8.0f, 0.0f, 2.0f);
	glVertex3f(8.0f, 0.0f, -2.0f);

	//front red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 3.0f, 2.0f);
	glVertex3f(-5.0f, 0.0f, 2.0f);
	glVertex3f(-8.0f, 0.0f, 2.0f);
	glVertex3f(-8.0f, 3.0f, 2.0f);

	//back red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 3.0f, -2.0f);
	glVertex3f(-5.0f, 0.0f, -2.0f);
	glVertex3f(-8.0f, 0.0f, -2.0f);
	glVertex3f(-8.0f, 3.0f, -2.0f);

	//left red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 3.0f, 2.0f);
	glVertex3f(-5.0f, 0.0f, 2.0f);
	glVertex3f(-5.0f, 0.0f, -2.0f);
	glVertex3f(-5.0f, 3.0f, -2.0f);

	//right red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-8.0f, 3.0f, 2.0f);
	glVertex3f(-8.0f, 0.0f, 2.0f);
	glVertex3f(-8.0f, 0.0f, -2.0f);
	glVertex3f(-8.0f, 3.0f, -2.0f);

	//top red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 3.0f, -2.0f);
	glVertex3f(-5.0f, 3.0f, 2.0f);
	glVertex3f(-8.0f, 3.0f, 2.0f);
	glVertex3f(-8.0f, 3.0f, -2.0f);

	//bottom red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 0.0f, -2.0f);
	glVertex3f(-5.0f, 0.0f, 2.0f);
	glVertex3f(-8.0f, 0.0f, 2.0f);
	glVertex3f(-8.0f, 0.0f, -2.0f);

	//body
	//top
	glColor3f(0.83f, 0.83f, 0.83f);
	glVertex3f(-5.0f, 3.0f, 2.0f);
	glVertex3f(-5.0f, 3.0f, -2.0f);
	glVertex3f(5.0f, 3.0f, -2.0f);
	glVertex3f(5.0f, 3.0f, 2.0f);

	//bottom
	glColor3f(0.83f, 0.83f, 0.83f);
	glVertex3f(-5.0f, 0.0f, 2.0f);
	glVertex3f(-5.0f, 0.0f, -2.0f);
	glVertex3f(5.0f, 0.0f, -2.0f);
	glVertex3f(5.0f, 0.0f, 2.0f);

	//front
	glColor3f(0.83f, 0.83f, 0.83f);
	glVertex3f(-5.0f, 3.0f, 2.0f);
	glVertex3f(-5.0f, 0.0f, 2.0f);
	glVertex3f(5.0f, 0.0f, 2.0f);
	glVertex3f(5.0f, 3.0f, 2.0f);

	//back
	glColor3f(0.83f, 0.83f, 0.83f);
	glVertex3f(-5.0f, 3.0f, -2.0f);
	glVertex3f(-5.0f, 0.0f, -2.0f);
	glVertex3f(5.0f, 0.0f, -2.0f);
	glVertex3f(5.0f, 3.0f, -2.0f);

	glEnd();
	// drawBoundingBox(17.0, 3.0, 5.0);
}
