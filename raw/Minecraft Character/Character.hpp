#ifndef YP_Character_HPP
#define YP_Character_HPP
#include "CGLabmain.hpp"
#include <string>
#include <vector>

namespace Character {
class Cha
{
    public:
    Cha();
    void Eye();
    void Nose();
    void Hair();
    void Mouth();
    void Face();
    void Head();
    void Body();
    void Hand();
    void Leg();
    void drawAnimation();
    void drawStatic();
    void tickTime(long int elapseTime);

    private:
    GLUquadricObj *pObj;
    GLfloat leftlegsangle; //in degree
    GLfloat leftlegsspeed; //in degree per sec
    GLfloat rightlegsangle; //in degree
    GLfloat rightlegsspeed; //in degree per sec
};

class MyVirtualWorld
{
    public:
    Cha cha;
    long int timeold, timenew, elapseTime;

    void draw()
    {
        //cha.Eye();
        //cha.Nose();
        //cha.Mouth();
        //cha.Hair();
        //cha.Face();
        //cha.Head();
        //cha.Body();
        //cha.Hand();
        //cha.Leg();
        cha.drawAnimation();
        //cha.drawStatic();
    }
    void tickTime()
    {
        timenew = glutGet(GLUT_ELAPSED_TIME);
        elapseTime = timenew - timeold;
        timeold = timenew;
        cha.tickTime(elapseTime);
    }

    void init()
    {
        timeold = glutGet(GLUT_ELAPSED_TIME);
    }
};
};
#endif

