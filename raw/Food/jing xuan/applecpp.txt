#include <GL/glut.h>
#include "CGLab04.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>


using namespace CGLab04;

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

void Myapple::drawapple()
{

    glDisable(GL_CULL_FACE);
    //Quadric Object
    GLUquadricObj *pObj;
    //create and initialize quadric
    pObj = gluNewQuadric();

    gluQuadricNormals(pObj, GLU_SMOOTH);
    //gluQuadricNormals(pObj, GLU_FLAT);

    glPushMatrix(); //apple
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 4.0f, 0.0f);
    gluSphere(pObj, 4.0f, 24, 12);
    glPopMatrix();

    glPushMatrix();//apple stick
    glColor3f(0.55f, 0.27f, 0.1f);
    glTranslatef(0.0f,11.0f, 0.0f);
    glRotatef(90.0, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 0.8f, 0.5f, 4.0f, 24, 72);
    glPopMatrix();

    drawBoundingBox(7.0, 10.0, 7.0);

}

void Myleaf::drawleaf()
{

    glDisable(GL_CULL_FACE);

    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.0, 4.5);
    glVertex2f(0.0, 4.5);
    glVertex2f(4.0, 9.5);
    glVertex2f(0.0, 8.0);
    glEnd();

    glEnable(GL_CULL_FACE);
}
