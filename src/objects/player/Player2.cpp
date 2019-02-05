#include "pch.h"
#include "Player2.h"

void Player2::Animate()
{
	_left.x += _left.y * _elapsed;
	Wrap(_left.x, _left.y, _left.z, _left.a, WrappingBehaviour::Bounce);
	_right.x += _right.y * _elapsed;
	Wrap(_right.x, _right.y, _right.z, _right.a, WrappingBehaviour::Bounce);
}

void Player2::Render()
{
	Apply();
	if (HasPositionChanged()) Animate();
	OrientDirection();

	RenderStats(35);

	GLUquadricObj* pObj = gluNewQuadric();

	// left foot
	glPushMatrix();
	{
		glTranslatef(-2.5f, 6.0f, 0.0f);
		glRotatef(_right.x, 1, 0, 0);
		Foot();
	}
	glPopMatrix();

	// right foot
	glPushMatrix();
	{
		glTranslatef(2.5f, 6.0f, 0.0f);
		glRotatef(_left.x, 1, 0, 0);
		Foot();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 3.0f, 0.0f);
	Body();
	Hand();
	glPopMatrix();

	//head
	glPushMatrix();
	glColor3f(0.196078f, 0.6f, 0.8f);
	glTranslatef(0.0f, 17.0f, 0.0f);
	gluSphere(pObj, 6.5f, 24, 12);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 17.0f, 1.0f);
	gluSphere(pObj, 5.9f, 24, 12);
	glPopMatrix();

	//left top beard
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-6.0, 19.0, 7.0);
	glVertex3f(-2.0, 18.0, 7.0);

	//right top beard
	glVertex3f(6.0, 19.0, 7.0);
	glVertex3f(2.0, 18.0, 7.0);

	//left middle beard
	glVertex3f(-6.0, 17.0, 7.0);
	glVertex3f(-2.0, 17.0, 7.0);

	//right middle beard
	glVertex3f(6.0, 17.0, 7.0);
	glVertex3f(2.0, 17.0, 7.0);

	//left below beard
	glVertex3f(-6.0, 15.0, 7.0);
	glVertex3f(-2.0, 16.0, 7.0);

	//right below beard
	glVertex3f(6.0, 15.0, 7.0);
	glVertex3f(2.0, 16.0, 7.0);

	//line between nose and mouth
	glVertex3f(0.0, 18.5, 7.0);
	glVertex3f(0.0, 17.0, 7.0);

	glEnd();
	glPopMatrix();

	//left eye
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-1.0f, 21.0f, 3.5f);
	gluSphere(pObj, 2.0f, 24, 12);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(-1.0f, 21.0f, 5.5f);
	gluSphere(pObj, 0.5f, 24, 12);
	glPopMatrix();

	//right eye
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(1.0f, 21.0f, 3.5f);
	gluSphere(pObj, 2.0f, 24, 12);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(1.0f, 21.0f, 5.5f);
	gluSphere(pObj, 0.5f, 24, 12);
	glPopMatrix();

	//Mouth
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, 17.0f, 6.9f);
	glVertex3f(0.0f, 15.0f, 6.8f);
	glVertex3f(3.0f, 17.0f, 6.9f);
	glEnd();

	//nose
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 19.0f, 6.0f);
	gluSphere(pObj, 0.8f, 24, 12);
	glPopMatrix();
}

void Player2::Body()
{
	GLUquadricObj* pObj = gluNewQuadric();

	//body
	glPushMatrix();
	glColor3f(0.196078f, 0.6f, 0.8f);
	glTranslatef(0.0f, 2.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 5.0f, 5.0f, 8.0f, 26, 13);
	glPopMatrix();

	//body cover
	glPushMatrix();
	glColor3f(0.196078f, 0.6f, 0.8f);
	glTranslatef(0.0f, 2.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluDisk(pObj, 0.0f, 5.0f, 26, 13);
	glPopMatrix();

	//pocket
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 6.0f, 2.0f);
	gluSphere(pObj, 4.0f, 24, 12);
	glPopMatrix();

	//belt
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 10.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 5.0f, 5.0f, 1.0f, 26, 13);
	glPopMatrix();

	//ring
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 10.0f, 6.0f);
	gluSphere(pObj, 1.0f, 24, 12);
	glPopMatrix();
}

void Player2::Hand()
{
	GLUquadricObj* pObj = gluNewQuadric();

	//left hand
	glPushMatrix();
	glColor3f(0.196078f, 0.6f, 0.8f);
	glTranslatef(-4.0f, 9.0f, 0.0f);
	glRotatef(-45.0, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 1.5, 1.5f, 6.0f, 26, 13);
	glPopMatrix();

	//left palm
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-9.0f, 4.0f, 0.0f);
	gluSphere(pObj, 1.8f, 24, 12);
	glPopMatrix();


	//right hand
	glPushMatrix();
	glColor3f(0.196078f, 0.6f, 0.8f);
	glTranslatef(4.0f, 9.0f, 0.0f);
	glRotatef(45.0, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 1.5, 1.5f, 6.0f, 26, 13);
	glPopMatrix();

	//right palm
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(9.0f, 4.0f, 0.0f);
	gluSphere(pObj, 1.8f, 24, 12);
	glPopMatrix();
}

void Player2::Foot()
{
	GLUquadricObj* pObj = gluNewQuadric();

	glPushMatrix();
	{
		glRotatef(90, 1, 0, 0);
		glColor3f(0.196078f, 0.6f, 0.8f);
		gluCylinder(pObj, 2.5, 2.5f, 3.5f, 26, 13);
		glTranslatef(0, 0, 3.5f);
		glColor3f(1.0f, 1.0f, 1.0f);
		gluSphere(pObj, 2.5f, 24, 12);
	}
	glPopMatrix();

}
