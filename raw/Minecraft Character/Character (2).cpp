#include <GL/glut.h>
#include <string>
#include <fstream>
#include "Character.hpp"

using namespace Character;

Cha::Cha()
{
    leftlegsangle = 30.0f; //in degree          //righthandangle
    leftlegsspeed = 90.0f; //in degree per sec  //righthandspeed
    rightlegsangle = -30.0f;                    //lefthandangle
    rightlegsspeed = 90.0f;                     //lefthandangle
}

void Cha::Eye()
{
    glDisable(GL_CULL_FACE);

    glPushMatrix();
    glTranslatef(-3.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);

    glTranslatef(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);

    glTranslatef(1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);
    glPopMatrix();

    glEnable(GL_CULL_FACE);
}

void Cha::Nose()
{
glDisable(GL_CULL_FACE);
glPushMatrix();
    glColor3f(0.62f, 0.36f, 0.20f);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRectf(2.0f, 1.0f, 0.0f, 0.0f);
glPopMatrix();
glEnable(GL_CULL_FACE);
}

void Cha::Mouth()
{
glDisable(GL_CULL_FACE);
glPushMatrix();
    glColor3f(0.29f, 0.15f, 0.05f);
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(3.0f, 0.0f, 0.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-3.0f, -1.0f, 0.0f);
    glRectf(4.0f, 1.0f, 0.0f, 0.0f);
glPopMatrix();
glEnable(GL_CULL_FACE);
}

void Cha::Hair()
{
    glDisable(GL_CULL_FACE);
glColor3f(0.29f, 0.15f, 0.05f);
    //top hair
    glPushMatrix();
    glColor3f(0.29f, 0.15f, 0.05f);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glTranslatef(-4.0f, -4.0f, -4.001f);
    glRectf(8.0f, 8.0f, 0.0f, 0.0f);
    glPopMatrix();
    //back hair
    glPushMatrix();
    glColor3f(0.29f, 0.15f, 0.05f);
    glTranslatef(-4.0f, -4.0f, -4.01f);
    glRectf(8.0f, 8.0f, 0.0f, 0.0f);
    glPopMatrix();
    //front hair
    glPushMatrix();
    glTranslatef(-4.0f, 3.01f, 4.01f);
    glRectf(8.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRectf(8.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(7.0f, 0.0f, 0.0f);
    glRectf(1.0f, 1.0f, 0.0f, 0.0f);
    glPopMatrix();
    //left hair
    glPushMatrix();
    glTranslatef(-4.01f, -1.0f, 4.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRectf(1.0f, 5.0f, 0.0f, 0.0f);
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRectf(2.0f, 4.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, -2.0f, 0.0f);
    glRectf(2.0f, 6.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, -1.0f, 0.0f);
    glRectf(2.0f, 7.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, -1.0f, 0.0f);
    glRectf(1.0f, 8.0f, 0.0f, 0.0f);
    glPopMatrix();
    //right hair
    glPushMatrix();
    glTranslatef(4.01f, -1.0f, 4.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRectf(1.0f, 5.0f, 0.0f, 0.0f);
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRectf(2.0f, 4.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, -2.0f, 0.0f);
    glRectf(2.0f, 6.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, -1.0f, 0.0f);
    glRectf(2.0f, 7.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, -1.0f, 0.0f);
    glRectf(1.0f, 8.0f, 0.0f, 0.0f);
    glPopMatrix();
    glEnable(GL_CULL_FACE);
}

void Cha::Face()
{
glTranslatef(0.0f, 1.0f, 0.0f);
Eye();
glTranslatef(0.0f, -1.0f, 0.0f);
Nose();
glTranslatef(0.0f, -1.0f, 0.0f);
Mouth();
}

void Cha::Head()
{
glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(1.0f, 0.91f, 0.67f);
	//glScalef(1.0f,1.0f,1.0f);
	glutSolidCube(8);
glPopAttrib();
glPopMatrix();

Hair();
glTranslatef(0.0f, -2.0f, 4.01f);
Face();
}

void Cha::Body()
{
glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
    glColor3f(0.08f, 0.74f, 0.72f);
	glScalef(8.0f, 10.0f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();
glPopAttrib();

}

void Cha::Hand()
{
glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
    glColor3f(0.08f, 0.74f, 0.72f);
	glTranslatef(0.0, 4.0f, 0.0f);
	glutSolidCube(3);
	glPopMatrix();


	glPushMatrix();
    glColor3f(1.0f, 0.91f, 0.67f);
    glTranslatef(0.0, -1.0f, 0.0f);
	glScalef(3.0f, 7.0f, 3.0f);
	glutSolidCube(1);
	glPopMatrix();
glPopAttrib();

}

void Cha::Leg()
{
glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
    glColor3f(0.04f, 0.43f, 0.67f);

	glTranslatef(0.0, 0.5f, 0.0f);
	glScalef(4.0f, 6.0f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
    glColor3f(0.08f, 0.74f, 0.72f);
    glTranslatef(0.0, -3.0f, 0.0f);
	glScalef(4.0f, 1.0f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();
glPopAttrib();
}

void BoundingBox(GLfloat xlength, GLfloat ylength, GLfloat zlength)
{
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0, ylength / 2.0f, 0);
	glScalef(xlength, ylength, zlength);
	glutWireCube(1);
	glPopAttrib();
	glPopMatrix();
}

void Cha::tickTime(long int elapseTime)
{
    float elapseTimeInSec = elapseTime / 1000.0f;
    leftlegsangle += elapseTimeInSec * leftlegsspeed;
    rightlegsangle += elapseTimeInSec * rightlegsspeed;

    if(leftlegsangle > 30)
    {
        leftlegsangle = 30;
        leftlegsspeed = -leftlegsspeed;
    }
    else if(leftlegsangle < -30)
    {
        leftlegsangle = -30;
        leftlegsspeed = -leftlegsspeed;
    }

    if(rightlegsangle < -30)
    {
        rightlegsangle = -30;
        rightlegsspeed = -rightlegsspeed;
    }
    else if(rightlegsangle > 30)
    {
        rightlegsangle = 30;
        rightlegsspeed = -rightlegsspeed;
    }
}

void Cha::drawAnimation()
{
    glPushMatrix();
    glTranslatef(0.0f, 21.0f, 0.0f);
    Head();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 12.0f, 0.0f);
    Body();
    glPopMatrix();
    //right hand
    glPushMatrix();
    glTranslatef(5.5f, 16.5f, -0.5f);
    glRotatef(rightlegsangle, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -5.0f, 0.0f);
    Hand();
    glPopMatrix();
    //left hand
    glPushMatrix();
    glTranslatef(-5.5f, 16.5f, -0.5f);
    glRotatef(leftlegsangle, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -5.0f, 0.0f);
    Hand();
    glPopMatrix();
    //right leg
    glPushMatrix();
    glTranslatef(2.0f, 8.5f, 0.0f);
    glRotatef(leftlegsangle, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -5.0f, 0.0f);
    Leg();
    glPopMatrix();
    //left leg
    glPushMatrix();
    glTranslatef(-2.0f, 8.5f, 0.0f);
    glRotatef(rightlegsangle, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -5.0f, 0.0f);
    Leg();
    glPopMatrix();

    float ylength = 25;
    float xlength = 14;
    float zlength = 8;
    BoundingBox(xlength, ylength, zlength);
}

void Cha::drawStatic()
{
    glPushMatrix();
    glTranslatef(0.0f, 21.0f, 0.0f);
    Head();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 12.0f, 0.0f);
    Body();
    glPopMatrix();
    //right hand
    glPushMatrix();
    glTranslatef(5.5f, 11.5f, -0.5f);
    Hand();
    glPopMatrix();
    //left hand
    glPushMatrix();
    glTranslatef(-5.5f, 11.5f, -0.5f);
    Hand();
    glPopMatrix();
    //right leg
    glPushMatrix();
    glTranslatef(2.0f, 3.5f, 0.0f);
    Leg();
    glPopMatrix();
    //left leg
    glPushMatrix();
    glTranslatef(-2.0f, 3.5f, 0.0f);
    Leg();
    glPopMatrix();

    float ylength = 25;
    float xlength = 14;
    float zlength = 8;
    BoundingBox(xlength, ylength, zlength);
}

