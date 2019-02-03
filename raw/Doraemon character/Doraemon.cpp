#include <GL/glut.h>
#include <string>
#include <fstream>
#include "Doraemon.hpp"

using namespace Doraemon;
Dora::Dora()
{
//Setup Quadric Object
pObj = gluNewQuadric();
gluQuadricNormals(pObj, GLU_SMOOTH);
}
Dora::~Dora()
{
gluDeleteQuadric(pObj);
}


void Dora::drawBody()
{

glDisable(GL_CULL_FACE);
//Quadric Object
GLUquadricObj *pObj;
//create and initialize quadric
pObj = gluNewQuadric();

//body
glPushMatrix();
glColor3f(0.196078f, 0.6f, 0.8f);
glTranslatef(0.0f, 2.0f, 0.0f);
glRotatef(-90.0f,1.0f,0.0f,0.0f);
gluCylinder(pObj,5.0f, 5.0f, 8.0f, 26, 13);
glPopMatrix();

//body cover
glPushMatrix();
glColor3f(0.196078f, 0.6f, 0.8f);
glTranslatef(0.0f, 2.0f, 0.0f);
glRotatef(-90.0f,1.0f,0.0f,0.0f);
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
glRotatef(-90.0f,1.0f,0.0f,0.0f);
gluCylinder(pObj,5.0f, 5.0f, 1.0f, 26, 13);
glPopMatrix();

//ring
glPushMatrix();
glColor3f(1.0f, 1.0f, 0.0f);
glTranslatef(0.0f, 10.0f, 6.0f);
gluSphere(pObj, 1.0f, 24, 12);
glPopMatrix();
}
void Dora::drawHand()
{
glDisable(GL_CULL_FACE);
//Quadric Object
GLUquadricObj *pObj;
//create and initialize quadric
pObj = gluNewQuadric();

drawBody();

//left hand
glPushMatrix();
glColor3f(0.196078f, 0.6f, 0.8f);
glTranslatef(-4.0f,9.0f,0.0f);
glRotatef(-45.0,0.0f,0.0f,1.0f);
glRotatef(90.0,1.0f,0.0f,0.0f);
gluCylinder(pObj,1.5, 1.5f, 6.0f, 26, 13);
glPopMatrix();

//right hand
glPushMatrix();
glColor3f(0.196078f, 0.6f, 0.8f);
glTranslatef(4.0f,9.0f,0.0f);
glRotatef(45.0,0.0f,0.0f,1.0f);
glRotatef(90.0,1.0f,0.0f,0.0f);
gluCylinder(pObj,1.5, 1.5f, 6.0f, 26, 13);
glPopMatrix();

//left palm
glPushMatrix();
glColor3f(1.0f, 1.0f, 1.0f);
glTranslatef(-9.0f, 4.0f, 0.0f);
gluSphere(pObj, 1.8f, 24, 12);
glPopMatrix();

//left palm
glPushMatrix();
glColor3f(1.0f, 1.0f, 1.0f);
glTranslatef(9.0f, 4.0f, 0.0f);
gluSphere(pObj, 1.8f, 24, 12);
glPopMatrix();
}
void Dora:: drawFoot()
{
glDisable(GL_CULL_FACE);
//Quadric Object
GLUquadricObj *pObj;
//create and initialize quadric
pObj = gluNewQuadric();

drawHand();

//left foot
glPushMatrix();
glColor3f(0.196078f, 0.6f, 0.8f);
glTranslatef(-2.5f,2.0f,0.0f);
glRotatef(90.0,1.0f,0.0f,0.0f);
gluCylinder(pObj,2.5, 2.5f, 3.0f, 26, 13);
glPopMatrix();

//right foot
glPushMatrix();
glColor3f(0.196078f, 0.6f, 0.8f);
glTranslatef(2.5f,2.0f,0.0f);
glRotatef(90.0,1.0f,0.0f,0.0f);
gluCylinder(pObj,2.5, 2.5f, 3.0f, 26, 13);
glPopMatrix();

//left sole
glPushMatrix();
glColor3f(1.0f, 1.0f, 1.0f);
glTranslatef(-2.5f, -1.0f, 0.0f);
gluSphere(pObj,2.5f, 24, 12);
glPopMatrix();

//right sole
glPushMatrix();
glColor3f(1.0f, 1.0f, 1.0f);
glTranslatef(2.5f, -1.0f, 0.0f);
gluSphere(pObj,2.5f, 24, 12);
glPopMatrix();
}

void drawBoundingBox(GLfloat xlength, GLfloat ylength, GLfloat zlength)
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

void Dora:: draw()
{
glDisable(GL_CULL_FACE);
//Quadric Object
GLUquadricObj *pObj;
//create and initialize quadric
pObj = gluNewQuadric();

glPushMatrix();
glTranslatef(0.0f, 2.0f, 0.0f);
drawFoot();
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
glDisable(GL_CULL_FACE); //disable face culling
glPushMatrix();
glBegin(GL_LINES);
glColor3f(0.0, 0.0, 0.0);
glVertex3f(-6.0, 19.0, 7.0);
glVertex3f( -2.0, 18.0, 7.0);

//right top beard
glVertex3f(6.0, 19.0, 7.0);
glVertex3f( 2.0, 18.0, 7.0);

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
glEnable(GL_CULL_FACE); //restore back the default setting

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
glDisable(GL_CULL_FACE); //disable face culling
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f );
glVertex3f( -3.0f, 17.0f, 6.9f );
glVertex3f( 0.0f, 15.0f, 6.8f );
glVertex3f( 3.0f, 17.0f, 6.9f );
glEnd();
glEnable(GL_CULL_FACE); //restore back the default setting

//nose
glPushMatrix();
glColor3f(1.0f, 0.0f, 0.0f);
glTranslatef(0.0f, 19.0f, 6.0f);
gluSphere(pObj, 0.8f, 24, 12);
glPopMatrix();

//draw bounding box
float ylength = 23;
float xlength = 17;
float zlength = 9;
drawBoundingBox(xlength, ylength, zlength);

}
