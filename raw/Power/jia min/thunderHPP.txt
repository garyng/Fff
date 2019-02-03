#ifndef YP_CGLAB05_HPP
#define YP_CGLAB05_HPP
#include "CGLabmain.hpp"
namespace CGLab05 {
class MyThunder
{
public:
    void drawThunder();
};

class MyVirtualWorld
{
public:

  MyThunder mythunder;

 void draw()
 {
 mythunder.drawThunder();

 }


 void init()
 {
 }
};
}; 
#endif 