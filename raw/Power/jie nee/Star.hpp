#ifndef YP_Star_HPP
#define YP_Star_HPP
#include "CGLabmain.hpp"
namespace Star {



class MyStar
{
public:
    void drawstar();
    void drawdisk();
    void drawcombine();
    void finalstar();

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

private:
};


class MyVirtualWorld
{
public:
    MyStar mystar;

 MyVirtualWorld()
 {
 }


 void draw()
 {
    //mystar.drawstar();
    //mystar.drawdisk();
    //mystar.drawcombine();
    mystar.finalstar();

 }


 void tickTime()
 {
 //do nothing, reserved for doing animation


 }
 //for any one-time only initialization of the
 // virtual world before any rendering takes place
 // BUT after OpenGL has been initialized
 void init()
 {

 }
};
}; //end of namespace CGLab03
#endif //YP_CGLAB03_HPP

