#ifndef YP_CGLAB05_HPP
#define YP_CGLAB05_HPP
#include "CGLabmain.hpp"
namespace CGLab05 {
class MySandwich
{
public:
    void drawSandwich();
};

class MyVirtualWorld
{
public:
    MySandwich mysandwich;

void draw()
 {
 mysandwich.drawSandwich();

 }

 void init()
 {
 }
};
}; 
#endif 
