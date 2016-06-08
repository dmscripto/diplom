#ifndef ROBOMATH_H
#define ROBOMATH_H

#include <opencv2/core.hpp>
#include "settings.h"

using namespace cv;

enum Directions
{
   LEFT,
   RIGHT,
   FORWARD,
   BACKWARD
};

class Robomath
{	
    const double PI = 3.14159265359;
    double scalex;
    double scaley;
    RobotSettings* sets;
    Point imagesize;
    
public:
    Robomath(RobotSettings* sets, Point imagesize);
    void calcscale(Point p1, Point p2,  double roborx, double robory);
    double calcrlength(Point p1, Point p2);
    double calcangle(Point p1, Point p2, Point p3);
    double calcangle_noninvert(Point p1, Point p2, Point p3);
    Point calccenter(Point p1, Point p2);
    Point makeinvert(Point p1, Point p2);
    Directions calcdirection(Point p1, Point p2, Point p3);
    std::string makecmd(Directions dir, int count);
    int calcstepscmd(double rsize, Directions dir);
    Point inverty(Point p);
};

#endif