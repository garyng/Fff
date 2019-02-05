#include <GL/glut.h>
#include "CGLab05.hpp"
using namespace CGLab05;
void drawBoundingBox(GLfloat xlength, GLfloat ylength, GLfloat zlength)
{
	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, ylength / 2.0f, 0);
	glScalef(xlength, ylength, zlength);
	glutWireCube(1);
	glPopAttrib();
	glPopMatrix();
}

void MyIcecream::drawIcecream()
{
glDisable(GL_CULL_FACE);
//Quadric Object
GLUquadricObj *pObj;
//create and initialize quadric
pObj = gluNewQuadric();
gluQuadricNormals(pObj, GLU_SMOOTH);

glPushMatrix();
glColor3f(0.87f, 0.72f, 0.53f);
glTranslatef(0.0f, 0.0f, 0.0f);
glRotatef(180.0f, 0.0f, 1.0f, 1.0f);
gluCylinder(pObj,0.0f, 7.0f, 25.0f, 20, 72);
glPopMatrix();

glPushMatrix();
glColor3f(0.8f, 0.8f, 0.8f);
glTranslatef(0.0f, 30.0f, 0.0f);
//glRotatef(90.0f, 1.0f, 0.0f, 1.0f);
gluSphere(pObj, 10.0f, 24, 12);
glPopMatrix();

glEnd();
gluDeleteQuadric(pObj);
glEnable(GL_CULL_FACE);


float ylength = (20+10) * sin(1.047);
float xlength = (20+10 ) * cos(1.047);
float zlength = 10 * 2;
drawBoundingBox(23, 40, 20);

}