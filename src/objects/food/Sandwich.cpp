#include "pch.h"
#include "Sandwich.h"

void Sandwich::Render()
{
	Apply();

	glBegin(GL_TRIANGLES);
	//toast
	//bottom
	glColor3f(0.96f, 0.87f, 0.7f);
	glPushMatrix();
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, -6.0f);
	glVertex3f(-10.0f, 0.0f, -6.0f);
	glPopMatrix();
	//top
	glPushMatrix();
	glVertex3f(-10.0f, 1.0f, 10.0f);
	glVertex3f(10.0f, 1.0f, -6.0f);
	glVertex3f(-10.0f, 1.0f, -6.0f);
	glPopMatrix();
	//VEG
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glVertex3f(-10.0f, 2.0f, 10.0f);
	glVertex3f(10.0f, 2.0f, -6.0f);
	glVertex3f(-10.0f, 2.0f, -6.0f);
	glPopMatrix();
	//ham
	//bottom
	glPushMatrix();
	glColor3f(0.86f, 0.62f, 0.66f);
	glVertex3f(-10.0f, 2.2f, 10.0f);
	glVertex3f(10.0f, 2.2f, -6.0f);
	glVertex3f(-10.0f, 2.2f, -6.0f);
	glPopMatrix();
	//top
	glPushMatrix();
	glVertex3f(-10.0f, 4.0f, 10.0f);
	glVertex3f(10.0f, 4.0f, -6.0f);
	glVertex3f(-10.0f, 4.0f, -6.0f);
	glPopMatrix();
	//toast top
	glColor3f(0.96f, 0.87f, 0.7f);
	glPushMatrix();
	glVertex3f(-10.0f, 5.0f, 10.0f);
	glVertex3f(10.0f, 5.0f, -6.0f);
	glVertex3f(-10.0f, 5.0f, -6.0f);
	glPopMatrix();
	glEnd();

	glBegin(GL_QUADS);
	//toast
	//front
	glPushMatrix();
	glColor3f(0.96f, 0.87f, 0.7f);
	glVertex3f(-10.0f, 1.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, -6.0f);
	glVertex3f(10.0f, 1.0f, -6.0f);
	glPopMatrix();
	//right
	glPushMatrix();
	glVertex3f(10.0f, 1.0f, -6.0f);
	glVertex3f(10.0f, 0.0f, -6.0f);
	glVertex3f(-10.0f, 0.0f, -6.0f);
	glVertex3f(-10.0f, 1.0f, -6.0f);
	glPopMatrix();
	//left
	glPushMatrix();
	glVertex3f(-10.0f, 1.0f, -6.0f);
	glVertex3f(-10.0f, 0.0f, -6.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 1.0f, 10.0f);
	glPopMatrix();
	//veg
	//front
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-10.0f, 2.0f, 10.0f);
	glVertex3f(-10.0f, 1.0f, 10.0f);
	glVertex3f(10.0f, 1.0f, -6.0f);
	glVertex3f(10.0f, 2.0f, -6.0f);
	glPopMatrix();
	//right
	glPushMatrix();
	glVertex3f(10.0f, 2.0f, -6.0f);
	glVertex3f(10.0f, 1.0f, -6.0f);
	glVertex3f(-10.0f, 1.0f, -6.0f);
	glVertex3f(-10.0f, 2.0f, -6.0f);
	glPopMatrix();
	//left
	glPushMatrix();
	glVertex3f(-10.0f, 2.0f, -6.0f);
	glVertex3f(-10.0f, 1.0f, -6.0f);
	glVertex3f(-10.0f, 1.0f, 10.0f);
	glVertex3f(-10.0f, 2.0f, 10.0f);
	glPopMatrix();

	//ham front
	glPushMatrix();
	glColor3f(1.0f, 0.7f, 0.4f);
	glVertex3f(-10.0f, 4.0f, 10.0f);
	glVertex3f(-10.0f, 2.2f, 10.0f);
	glVertex3f(10.0f, 2.2f, -6.0f);
	glVertex3f(10.0f, 4.0f, -6.0f);
	glPopMatrix();
	//right
	glPushMatrix();
	glVertex3f(10.0f, 4.0f, -6.0f);
	glVertex3f(10.0f, 2.2f, -6.0f);
	glVertex3f(-10.0f, 2.2f, -6.0f);
	glVertex3f(-10.0f, 4.0f, -6.0f);
	glPopMatrix();
	//left
	glPushMatrix();
	glVertex3f(-10.0f, 4.0f, -6.0f);
	glVertex3f(-10.0f, 2.2f, -6.0f);
	glVertex3f(-10.0f, 2.2f, 10.0f);
	glVertex3f(-10.0f, 4.0f, 10.0f);
	glPopMatrix();

	//toast
	//front
	glPushMatrix();
	glColor3f(0.96f, 0.87f, 0.7f);
	glVertex3f(-10.0f, 5.0f, 10.0f);
	glVertex3f(-10.0f, 4.0f, 10.0f);
	glVertex3f(10.0f, 4.0f, -6.0f);
	glVertex3f(10.0f, 5.0f, -6.0f);
	glPopMatrix();
	//right
	glPushMatrix();
	glVertex3f(10.0f, 5.0f, -6.0f);
	glVertex3f(10.0f, 4.0f, -6.0f);
	glVertex3f(-10.0f, 4.0f, -6.0f);
	glVertex3f(-10.0f, 5.0f, -6.0f);
	glPopMatrix();
	//left
	glPushMatrix();
	glVertex3f(-10.0f, 5.0f, -6.0f);
	glVertex3f(-10.0f, 4.0f, -6.0f);
	glVertex3f(-10.0f, 4.0f, 10.0f);
	glVertex3f(-10.0f, 5.0f, 10.0f);
	glPopMatrix();


	glEnd();

	GLUquadricObj* pObj = gluNewQuadric();

	glPushMatrix();
	glColor3f(1.0f, 0.1f, 0.0f);
	glTranslatef(-7.0f, 2.1f, 4.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 1.0f);
	gluDisk(pObj, 0.0f, 5.0f, 20, 13);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.0f, 2.1f, -4.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 1.0f);
	gluDisk(pObj, 0.0f, 5.0f, 20, 13);
	glPopMatrix();
	glEnd();

	/*float ylength = (20) * sin(1.57);
	float xlength = (20) * cos(1.57);
	float zlength = 5 * 2;
	drawBoundingBox(23, 6, 20);*/
}
