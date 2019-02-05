#ifndef YP_CGLAB04_HPP
#define YP_CGLAB04_HPP

#include "CGLabmain.hpp"

namespace CGLab04 {

class Mymagnet {

    public:
        void drawmagnet();


    };

class MyVirtualWorld {

    public:
       
        Mymagnet magnet;

        void draw()
        {
            
            magnet.drawmagnet();
        }

}
#endif