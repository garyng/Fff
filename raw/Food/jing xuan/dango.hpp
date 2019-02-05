#ifndef YP_CGLAB04_HPP
#define YP_CGLAB04_HPP

#include "CGLabmain.hpp"

namespace CGLab04 {

 class Mydango {

 
    public:
        void drawdango();
  };

class MyVirtualWorld {

    public:
        Mydango dango;
        
        

    void draw()
        {
            dango.drawdango();
            
        }
        
}
#endif

