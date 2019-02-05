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


void Mydango::drawdango()
{
   glDisable(GL_CULL_FACE);
    //Quadric Object
    GLUquadricObj *pObj;
    //create and initialize quadric
    pObj = gluNewQuadric();

    gluQuadricNormals(pObj, GLU_SMOOTH);
    //gluQuadricNormals(pObj, GLU_FLAT);

    glPushMatrix(); //pink
    glColor3f(1.0f, 0.68f, 0.68f);
    glTranslatef(4.0f, 21.5f, 0.0f);
    gluSphere(pObj, 4.0f, 24, 12);
    glPopMatrix();

    glPushMatrix(); //yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 15.0f, 0.0f);
    gluSphere(pObj, 4.0f, 24, 12);
    glPopMatrix();

    glPushMatrix(); //purple
    glColor3f(0.87f, 0.63f, 0.87f);
    glTranslatef(-3.5f, 8.0f, 0.0f);
    gluSphere(pObj, 4.0f, 24, 12);
    glPopMatrix();

    glPushMatrix();// stick
    glColor3f(0.55f, 0.27f, 0.1f);
    glTranslatef(-8.0f, 0.0f, 0.0f);
    glRotatef(60.0, 0.0f, 0.0f, 1.0f);
    glRotatef(90.0, 0.0f, 1.0f, 0.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 30.5f, 24, 72);
    glPopMatrix();

    drawBoundingBox(15.0, 25.0, 8.0);


}