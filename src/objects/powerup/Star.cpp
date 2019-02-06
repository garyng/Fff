#include "pch.h"
#include "Star.h"

void Star::Render()
{
	Apply();

	glPushMatrix();
	{
		glColor3f(0.682f, 0.776f, 0.812f);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(24, 5, 64, 64);
	}
	glPopMatrix();

	GLUquadricObj* pObj = gluNewQuadric();

	glLineWidth(3);
	glPointSize(2);
	glTranslatef(0.0f, 18.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(80, 1.0f, 1.0f, 0.0f);
	Disk();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(120, 0.0f, 1.0f, 1.0f);
	Disk();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, 6.0f, 5.0f);
	glRotatef(160, 1.0f, 1.0f, 0.0f);
	glScalef(0.2f, 0.2f, 1.0f);
	OneStar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-13.0f, -10.0f, 10.0f);
	glScalef(0.2f, 0.2f, 1.0f);
	OneStar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0f, -16.0f, 15.0f);
	glScalef(0.3f, 0.3f, 1.0f);
	OneStar();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(-9.5f, 10.5f, -5.0f);
	gluSphere(pObj, 1.0f, 24, 12);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 1.0f);
	glTranslatef(8.0f, 3.0f, -17.5f);
	gluSphere(pObj, 1.0f, 24, 12);
	glPopMatrix();

	gluDeleteQuadric(pObj);

	/*float xlength = (32);
	float ylength = (33);
	float zlength = 35.0;*/
}

void Star::OneStar()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex3f(3.0f, 0.0f, 0.0f); //1
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(12.0f, 6.0f, 0.0f); //3
	glVertex3f(12.0f, 6.0f, 0.0f); //3
	glVertex3f(6.0f, 10.0f, 0.0f); //4
	glVertex3f(6.0f, 10.0f, 0.0f); //4
	glVertex3f(0.0f, 6.0f, 0.0f); //5
	glVertex3f(0.0f, 6.0f, 0.0f); //5
	glVertex3f(3.0f, 0.0f, 0.0f); //1

	//down
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f); //1
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(6.0f, -9.0f, 0.0f); //3
	glVertex3f(6.0f, -9.0f, 0.0f); //3
	glVertex3f(3.0f, 0.0f, 0.0f); //1

	//left down
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f); //1
	glVertex3f(0.0f, 6.0f, 0.0f); //2
	glVertex3f(0.0f, 6.0f, 0.0f); //2
	glVertex3f(-8.0f, 0.0f, 0.0f); //3
	glVertex3f(-8.0f, 0.0f, 0.0f); //3
	glVertex3f(3.0f, 0.0f, 0.0f); //1

	//right down
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 0.0f, 0.0f); //1
	glVertex3f(12.0f, 6.0f, 0.0f); //2
	glVertex3f(12.0f, 6.0f, 0.0f); //2
	glVertex3f(20.0f, 0.0f, 0.0f); //3
	glVertex3f(20.0f, 0.0f, 0.0f); //3
	glVertex3f(9.0f, 0.0f, 0.0f); //1

	//left up
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 0.0f); //1
	glVertex3f(6.0f, 10.0f, 0.0f); //2
	glVertex3f(6.0f, 10.0f, 0.0f); //2
	glVertex3f(-3.0f, 15.0f, 0.0f); //3
	glVertex3f(-3.0f, 15.0f, 0.0f); //3
	glVertex3f(0.0f, 6.0f, 0.0f); //1

	//right up
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(6.0f, 10.0f, 0.0f); //1
	glVertex3f(12.0f, 6.0f, 0.0f); //2
	glVertex3f(12.0f, 6.0f, 0.0f); //2
	glVertex3f(14.0f, 15.0f, 0.0f); //3
	glVertex3f(14.0f, 15.0f, 0.0f); //3
	glVertex3f(6.0f, 10.0f, 0.0f); //1


	glVertex3f(1.0f, 1.0f, 0.0f); //1
	glVertex3f(9.0f, 0.0f, 1.5f); //2
	glVertex3f(9.0f, 0.0f, 1.5f); //2
	glVertex3f(12.0f, 6.0f, 1.5f); //3
	glVertex3f(12.0f, 6.0f, 1.5f); //3
	glVertex3f(6.0f, 10.0f, 1.5f); //4
	glVertex3f(6.0f, 10.0f, 1.5f); //4
	glVertex3f(0.0f, 6.0f, 1.5f); //5
	glVertex3f(0.0f, 6.0f, 1.5f); //5
	glVertex3f(3.0f, 0.0f, 1.5f); //1

	//down
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 1.5f); //1
	glVertex3f(9.0f, 0.0f, 1.5f); //2
	glVertex3f(9.0f, 0.0f, 1.5f); //2
	glVertex3f(6.0f, -9.0f, 1.5f); //3
	glVertex3f(6.0f, -9.0f, 1.5f); //3
	glVertex3f(3.0f, 0.0f, 1.5f); //1

	//left down
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 1.5f); //1
	glVertex3f(0.0f, 6.0f, 1.5f); //2
	glVertex3f(0.0f, 6.0f, 1.5f); //2
	glVertex3f(-8.0f, 0.0f, 1.5f); //3
	glVertex3f(-8.0f, 0.0f, 1.5f); //3
	glVertex3f(3.0f, 0.0f, 1.5f); //1

	//right down
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 0.0f, 1.5f); //1
	glVertex3f(12.0f, 6.0f, 1.5f); //2
	glVertex3f(12.0f, 6.0f, 1.5f); //2
	glVertex3f(20.0f, 0.0f, 1.5f); //3
	glVertex3f(20.0f, 0.0f, 1.5f); //3
	glVertex3f(9.0f, 0.0f, 1.5f); //1

	//left up
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 6.0f, 1.5f); //1
	glVertex3f(6.0f, 10.0f, 1.5f); //2
	glVertex3f(6.0f, 10.0f, 1.5f); //2
	glVertex3f(-3.0f, 15.0f, 1.5f); //3
	glVertex3f(-3.0f, 15.0f, 1.5f); //3
	glVertex3f(0.0f, 6.0f, 1.5f); //1

	//right up
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(6.0f, 10.0f, 1.5f); //1
	glVertex3f(12.0f, 6.0f, 1.5f); //2
	glVertex3f(12.0f, 6.0f, 1.5f); //2
	glVertex3f(14.0f, 15.0f, 1.5f); //3
	glVertex3f(14.0f, 15.0f, 1.5f); //3
	glVertex3f(6.0f, 10.0f, 1.5f); //1

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(3.0f, 0.0f, 0.0f); //1
	glVertex3f(3.0f, 0.0f, 1.5f); //1
	glVertex3f(6.0f, -9.0f, 0.0f); //3
	glVertex3f(6.0f, -9.0f, 1.5f); //3
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(9.0f, 0.0f, 1.5f); //2
	glVertex3f(20.0f, 0.0f, 0.0f); //3
	glVertex3f(20.0f, 0.0f, 1.5f); //3
	glVertex3f(12.0f, 6.0f, 0.0f); //3
	glVertex3f(12.0f, 6.0f, 1.5f); //3
	glVertex3f(14.0f, 15.0f, 0.0f); //3
	glVertex3f(14.0f, 15.0f, 1.5f); //3
	glVertex3f(6.0f, 10.0f, 0.0f); //4
	glVertex3f(6.0f, 10.0f, 1.5f); //4
	glVertex3f(-3.0f, 15.0f, 0.0f); //3
	glVertex3f(-3.0f, 15.0f, 1.5f); //3
	glVertex3f(0.0f, 6.0f, 0.0f); //5
	glVertex3f(0.0f, 6.0f, 1.5f); //5
	glVertex3f(-8.0f, 0.0f, 0.0f); //3
	glVertex3f(-8.0f, 0.0f, 1.5f); //3

	glEnd();
}

void Star::Disk()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	float x, y, z;
	int t;
	glBegin(GL_POINTS);
	for (t = 0; t <= 360; t += 1)
	{
		x = 25 * sin(t);
		y = 10 * cos(t);
		z = 0;
		glVertex3f(x, y, z);
	}

	for (t = 0; t <= 360; t += 1)
	{
		x = 20 * sin(t);
		y = 7 * cos(t);
		z = 1.0;
		glVertex3f(x, y, z);
	}

	for (t = 0; t <= 360; t += 1)
	{
		x = 13 * sin(t);
		y = 5 * cos(t);
		z = -0.5;
		glVertex3f(x, y, z);
	}

	glEnd();
}
