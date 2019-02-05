#ifndef YP_CGLAB04_HPP
#define YP_CGLAB04_HPP

#include "CGLabmain.hpp"

namespace CGLab04 {

class Myapple {

    public:
        void drawapple();

    };

class Myleaf {

    public:
        void drawleaf();

    };

    class MyVirtualWorld {

    public:
        
        Myapple apple;
        Myleaf leaf;
        Mymagnet magnet;

        void draw()
        {
            
            apple.drawapple();
            leaf.drawleaf();
            
        }

}
#endif