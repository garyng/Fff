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

void MyThunder::drawThunder(){
glDisable(GL_CULL_FACE);

GLUquadricObj *pObj;
pObj = gluNewQuadric();
gluQuadricNormals(pObj, GLU_SMOOTH);

glPushMatrix();
glColor3f(1.0f,1.0f, 1.0f);
glTranslatef(1.0f, 15.0f, 1.0f);
gluSphere(pObj, 7.0f, 24, 12);

glTranslatef(6.0f, 0.0f, 0.0f);
gluSphere(pObj, 6.0f, 24, 12);

glTranslatef(-14.0f, 0.0f, 0.0f);
gluSphere(pObj, 6.0f, 24, 12);

glTranslatef(-5.0f, 0.0f, 0.0f);
gluSphere(pObj, 4.0f, 24, 12);

glTranslatef(26.0f, 0.0f, 0.0f);
gluSphere(pObj, 4.0f, 24, 12);

glPopMatrix();
glPushMatrix();
glColor3f(1.0f, 1.0f, 0.0f);
glTranslatef(0.0f, 15.0f, 1.0f);
glRotatef(110.0f, 0.0f, 1.0f, 1.0f);
gluCylinder(pObj,5.0f, 0.0f, 20.0f, 20, 72);
glPopMatrix();
glPushMatrix();
glColor3f(1.0f, 1.0f, 0.0f);
glTranslatef(0.0f, 15.0f, 1.0f);
glRotatef(250.0f, 0.0f, 20.0f, -10.0f);
gluCylinder(pObj,5.0f, 0.0f, 25.0f, 20, 72);
glPopMatrix();

glEnd();
gluDeleteQuadric(pObj);
glEnable(GL_CULL_FACE); //restore to default

float ylength = (25 + 4) * sin(2.18);
float xlength = (25 + 4) * cos(2.18);
float zlength = 4 * 2;
drawBoundingBox(39, 29, 16);

}