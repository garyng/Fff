#include "pch.h"
#include "Chocolate.h"

void Chocolate::Render()
{
	Apply();

	glLineWidth(3.0);
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(-4.5, -0.5, -14);
	Draw();
	glPopMatrix();
}

void Chocolate::Base()
{
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.098f, 0.0);

	//base
	glVertex3f(0.0f, 0.0f, 0.0f); //1
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(9.0f, 0.0f, 0.0f); //2
	glVertex3f(9.0f, 0.0f, 14.0f); //3
	glVertex3f(9.0f, 0.0f, 14.0f); //3
	glVertex3f(0.0f, 0.0f, 14.0f); //4
	glVertex3f(0.0f, 0.0f, 14.0f); //4
	glVertex3f(0.0f, 0.0f, 0.0f); //1

	//top
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 1.0f, 14.0f);
	glVertex3f(9.0f, 1.0f, 14.0f);
	glVertex3f(0.0f, 1.0f, 14.0f);
	glVertex3f(0.0f, 1.0f, 14.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glVertex3f(9.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 14.0f);
	glVertex3f(0.0f, 0.0f, 14.0f);
	glVertex3f(9.0f, 1.0f, 14.0f);
	glVertex3f(9.0f, 0.0f, 14.0f);

	glEnd();
}

void Chocolate::SmallCube()
{
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.2f, 0.0f);

	//base
	glVertex3f(0.0f, 0.0f, 0.0f); //1
	glVertex3f(2.0f, 0.0f, 0.0f); //2
	glVertex3f(2.0f, 0.0f, 2.0f); //2
	glVertex3f(2.0f, 0.0f, 2.0f); //3
	glVertex3f(2.0f, 0.0f, 2.0f); //3
	glVertex3f(0.0f, 0.0f, 2.0f); //4
	glVertex3f(0.0f, 0.0f, 2.0f); //4
	glVertex3f(0.0f, 0.0f, 0.0f); //1

	//top
	glColor3f(0.6f, 0.298f, 0.0f);
	glVertex3f(0.5f, 0.5, 0.5f); //1
	glVertex3f(1.5f, 0.5f, 0.5f); //2
	glVertex3f(1.5f, 0.5f, 0.5f); //2
	glVertex3f(1.5f, 0.5f, 1.5f); //3
	glVertex3f(1.5f, 0.5f, 1.5f); //3
	glVertex3f(0.5f, 0.5f, 1.5f); //4
	glVertex3f(0.5f, 0.5f, 1.5f); //4
	glVertex3f(0.5f, 0.5f, 0.5f); //1

	glVertex3f(0.0f, 0.0f, 0.0f); //behind
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glVertex3f(0.0f, 0.0f, 2.0f); //front
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(1.5f, 0.5f, 1.5f);
	glVertex3f(0.5f, 0.5f, 1.5f);

	glVertex3f(0.0f, 0.0f, 0.0f); //left
	glVertex3f(0.0f, 0.0f, 2.0f);
	glVertex3f(0.5f, 0.5f, 1.5f);
	glVertex3f(0.5f, 0.5, 0.5f);

	glVertex3f(2.0f, 0.0f, 2.0f); //right
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 1.5f);

	glEnd();
}

void Chocolate::Draw()
{
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.098f, 0.0);
	glPushMatrix();
	Base();

	//first row left
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 1.0f);
	SmallCube();
	glPopMatrix();
	//first row middle
	glPushMatrix();
	glTranslatef(3.5f, 1.0f, 1.0f);
	SmallCube();
	glPopMatrix();
	//first row right
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, 1.0f);
	SmallCube();
	glPopMatrix();
	//second row left
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 3.5f);
	SmallCube();
	glPopMatrix();
	//second row middle
	glPushMatrix();
	glTranslatef(3.5f, 1.0f, 3.5f);
	SmallCube();
	glPopMatrix();
	//second row right
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, 3.5f);
	SmallCube();
	glPopMatrix();
	//third row left
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 6.0f);
	SmallCube();
	glPopMatrix();
	//third row middle
	glPushMatrix();
	glTranslatef(3.5f, 1.0f, 6.0f);
	SmallCube();
	glPopMatrix();
	//third row right
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, 6.0f);
	SmallCube();
	glPopMatrix();
	//fourth row left
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 8.5f);
	SmallCube();
	glPopMatrix();
	//fourth row middle
	glPushMatrix();
	glTranslatef(3.5f, 1.0f, 8.5);
	SmallCube();
	glPopMatrix();
	//fourth row right
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, 8.5f);
	SmallCube();
	glPopMatrix();
	//fifth row left
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 11.0f);
	SmallCube();
	glPopMatrix();
	//fifth row middle
	glPushMatrix();
	glTranslatef(3.5f, 1.0f, 11.0f);
	SmallCube();
	glPopMatrix();
	//fifth row right
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, 11.0f);
	SmallCube();
	glPopMatrix();

	glEnd();
}
