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

void Mymagnet::drawmagnet()
{

    glDisable(GL_CULL_FACE);

    glBegin(GL_QUADS);


//front blue
    glVertex3f(5.0f, 3.0f, 2.0f);
    glVertex3f(5.0f, 0.0f, 2.0f);
    glVertex3f(8.0f, 0.0f, 2.0f);
    glVertex3f(8.0f, 3.0f, 2.0f);

//back blue
    glVertex3f(5.0f, 3.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(8.0f, 0.0f, -2.0f);
    glVertex3f(8.0f, 3.0f, -2.0f);

//left blue
    glVertex3f(5.0f, 3.0f, 2.0f);
    glVertex3f(5.0f, 0.0f, 2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 3.0f, -2.0f);

//right blue
    glVertex3f(8.0f, 3.0f, 2.0f);
    glVertex3f(8.0f, 0.0f, 2.0f);
    glVertex3f(8.0f, 0.0f, -2.0f);
    glVertex3f(8.0f, 3.0f, -2.0f);

//top blue
    glVertex3f(5.0f, 3.0f, -2.0f);
    glVertex3f(5.0f, 3.0f, 2.0f);
    glVertex3f(8.0f, 3.0f, 2.0f);
    glVertex3f(8.0f, 3.0f, -2.0f);

//bottom blue
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, 2.0f);
    glVertex3f(8.0f, 0.0f, 2.0f);
    glVertex3f(8.0f, 0.0f, -2.0f);

//front red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 3.0f, 2.0f);
    glVertex3f(-5.0f, 0.0f, 2.0f);
    glVertex3f(-8.0f, 0.0f, 2.0f);
    glVertex3f(-8.0f, 3.0f, 2.0f);

//back red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 3.0f, -2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f( -8.0f, 0.0f, -2.0f);
    glVertex3f( -8.0f, 3.0f, -2.0f);

//left red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 3.0f, 2.0f);
    glVertex3f(-5.0f, 0.0f, 2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(-5.0f, 3.0f, -2.0f);

//right red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-8.0f, 3.0f, 2.0f);
    glVertex3f(-8.0f, 0.0f, 2.0f);
    glVertex3f(-8.0f, 0.0f, -2.0f);
    glVertex3f(-8.0f, 3.0f, -2.0f);

//top red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 3.0f, -2.0f);
    glVertex3f(-5.0f, 3.0f, 2.0f);
    glVertex3f(-8.0f, 3.0f, 2.0f);
    glVertex3f(-8.0f, 3.0f, -2.0f);

//bottom red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(-5.0f, 0.0f, 2.0f);
    glVertex3f(-8.0f, 0.0f, 2.0f);
    glVertex3f(-8.0f, 0.0f, -2.0f);

//body
//top
    glColor3f(0.83f,0.83f,0.83f);
    glVertex3f(-5.0f, 3.0f, 2.0f);
    glVertex3f(-5.0f, 3.0f, -2.0f);
    glVertex3f(5.0f, 3.0f, -2.0f);
    glVertex3f(5.0f, 3.0f, 2.0f);

//bottom
    glColor3f(0.83f,0.83f,0.83f);
    glVertex3f(-5.0f, 0.0f, 2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, 2.0f);

//front
    glColor3f(0.83f,0.83f,0.83f);
    glVertex3f(-5.0f, 3.0f, 2.0f);
    glVertex3f(-5.0f, 0.0f, 2.0f);
    glVertex3f(5.0f, 0.0f, 2.0f);
    glVertex3f(5.0f, 3.0f, 2.0f);

//back
    glColor3f(0.83f,0.83f,0.83f);
    glVertex3f(-5.0f, 3.0f, -2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 3.0f, -2.0f);


    glEnd();
    drawBoundingBox(17.0, 3.0, 5.0);
}
