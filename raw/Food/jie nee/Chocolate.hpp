#ifndef YP_Chocolate_HPP
#define YP_Chocolate_HPP
#include "CGLabmain.hpp"
namespace Chocolate
{

class MyChocolate
{
public:
    void draw();
    void drawsmallcube();
    void drawchocolate();
    void finalchocolate();


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
};


class MyVirtualWorld
{
public:
    MyChocolate mychocolate;

    MyVirtualWorld()
    {
    }


    void draw()
    {
        //mychocolate.draw();
        //mychocolate.drawsmallcube();
        //mychocolate.drawchocolate();
        mychocolate.finalchocolate();

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
