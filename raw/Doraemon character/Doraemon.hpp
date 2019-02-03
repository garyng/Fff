#ifndef YP_Doraemon_HPP
#define YP_Doraemon_HPP

#include "CGLabmain.hpp"
#include <string>
#include <vector>
namespace Doraemon {
class Dora
{
public:
Dora();
~Dora();
void draw();
void drawHand();
void drawBody();
void drawFoot();
private:
GLUquadricObj *pObj;
};
//------------------------------------
//the main program will call methods from this class
class MyVirtualWorld
{
public:
Dora dora;
void draw()
{
dora.draw();
//dora.drawBody();
//dora.drawHand();
//dora.drawFoot();
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
};
#endif //YP_Daraemon_HPP
