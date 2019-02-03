#ifndef YP_DashPower_HPP
#define YP_DashPower_HPP
#include "CGLabmain.hpp"
#include <string>
#include <vector>

namespace DashPower {
class DP
{
    public:
    DP();
    ~DP();
    void firstpart();   // rocket Nosecone
    void secondpart();  // BodyTube
    void thirdpart();   // Window
    void forthpart();   // Fins
    void finalpart();

    private:
    GLUquadricObj *qObj;
};

class MyVirtualWorld
{
    public:
    DP dp;

    void draw()
    {
        //dp.firstpart();
        //dp.secondpart();
        //dp.thirdpart();
        dp.forthpart();
        //dp.finalpart();
    }
    void tickTime()
    {

    }

    void init()
    {

    }
};
};
#endif


