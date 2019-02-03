#include <GL/glut.h>
#include "Chocolate.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace Chocolate;

//base
void MyChocolate::draw()
{

    glDisable(GL_CULL_FACE);
    glLineWidth(3.0); //set the line thickness
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
    glEnable(GL_CULL_FACE);
}
//top
void MyChocolate::drawsmallcube()
{
    glDisable(GL_CULL_FACE);

    glLineWidth(3.0); //set the line thickness
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

    glVertex3f(0.0f, 0.0f, 2.0f);//front
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
    glEnable(GL_CULL_FACE);
}

void MyChocolate::drawchocolate()
{

    glDisable(GL_CULL_FACE);

    glLineWidth(3.0); //set the line thickness
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.098f, 0.0);
     glPushMatrix();
    draw();

    //first row left
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 1.0f);
    drawsmallcube();
    glPopMatrix();
    //first row middle
    glPushMatrix();
    glTranslatef(3.5f, 1.0f, 1.0f);
    drawsmallcube();
    glPopMatrix();
    //first row right
    glPushMatrix();
    glTranslatef(6.0f, 1.0f, 1.0f);
    drawsmallcube();
    glPopMatrix();
    //second row left
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 3.5f);
    drawsmallcube();
    glPopMatrix();
    //second row middle
    glPushMatrix();
    glTranslatef(3.5f, 1.0f, 3.5f);
    drawsmallcube();
    glPopMatrix();
    //second row right
    glPushMatrix();
    glTranslatef(6.0f, 1.0f, 3.5f);
    drawsmallcube();
    glPopMatrix();
    //third row left
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 6.0f);
    drawsmallcube();
    glPopMatrix();
    //third row middle
    glPushMatrix();
    glTranslatef(3.5f, 1.0f, 6.0f);
    drawsmallcube();
    glPopMatrix();
    //third row right
    glPushMatrix();
    glTranslatef(6.0f, 1.0f, 6.0f);
    drawsmallcube();
    glPopMatrix();
    //fourth row left
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 8.5f);
    drawsmallcube();
    glPopMatrix();
    //fourth row middle
    glPushMatrix();
    glTranslatef(3.5f, 1.0f, 8.5);
    drawsmallcube();
    glPopMatrix();
    //fourth row right
    glPushMatrix();
    glTranslatef(6.0f, 1.0f, 8.5f);
    drawsmallcube();
    glPopMatrix();
    //fifth row left
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 11.0f);
    drawsmallcube();
    glPopMatrix();
    //fifth row middle
    glPushMatrix();
    glTranslatef(3.5f, 1.0f, 11.0f);
    drawsmallcube();
    glPopMatrix();
    //fifth row right
    glPushMatrix();
    glTranslatef(6.0f, 1.0f, 11.0f);
    drawsmallcube();
    glPopMatrix();

    glEnd();
    glEnable(GL_CULL_FACE);
}

void MyChocolate::finalchocolate()
{
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(-4.5, -0.5, -14);
    drawchocolate();
    glPopMatrix();
    glPushMatrix();
    glPopMatrix();

    float ylength = (14);
    float xlength = (9);
    float zlength = 1.5;
    drawBoundingBox(xlength, ylength, zlength);

}
