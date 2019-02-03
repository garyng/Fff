#include <GL/glut.h>
#include "Cup.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace Cup;


void MyCup::drawcup()
{
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 10.0f, 0.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    gluCylinder(pObj, 3.0f, 2.0f, 10.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 7.0f, 0.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    gluCylinder(pObj, 2.9f, 2.0f, 6.0f, 24, 72);
    glPopMatrix();

    //base
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    gluDisk(pObj, 0.0f, 2.0f, 26, 13);
    glPopMatrix();

    //cover
    glPushMatrix();
    glColor3f(1.0f, 0.2f, 0.2f);
    glTranslatef(0.0f, 10.0f, 0.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    gluCylinder(pObj, 3.0f, 3.4f, 0.8f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.2f, 0.2f);
    glTranslatef(0.0f, 10.0f, 0.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    gluDisk(pObj, 0.0f, 3.0f, 26, 13);
    glPopMatrix();

    //straw
    glPushMatrix();
    glColor3f(0.2f, 1.0f, 1.0f);
    glTranslatef(0.0f, 13.0f, 0.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    gluCylinder(pObj, 0.3f, 0.3f, 10.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2f, 1.0f, 1.0f);
    glTranslatef(-0.09f, 12.8f, 0.0f);
    glRotatef(110, 0.0, 1.0, 1.0);
    gluCylinder(pObj, 0.3f, 0.3f, 3.5f, 24, 72);
    glPopMatrix();

    gluDeleteQuadric(pObj);
    glEnable(GL_CULL_FACE);
}

void MyCup::finalcup()
{
    glPushMatrix();
    drawcup();
    glPopMatrix();

    float ylength = (15.5);
    float xlength = (6.5);
    float zlength = 6.0;
    drawBoundingBox(xlength, ylength, zlength);

}

