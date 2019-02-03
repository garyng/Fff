#ifndef YP_CGLAB05_HPP
#define YP_CGLAB05_HPP
#include "CGLabmain.hpp"
namespace CGLab05 {
class MyIcecream
{
 public :
     void drawIcecream();
};

class MyVirtualWorld
{
public:
  MyIcecream myicecream;

void draw()
 {
	myicecream.drawIcecream();

 }

 void init()
 {
 }
};
}; 
#endif 
