#include "robomath.h"

Robomath::Robomath(RobotSettings* sets, Point imagesize)
{
    scalex = 1;
    scaley = 1;
    this->sets = sets;
    this->imagesize = imagesize;
}


double Robomath::calcrlength(Point p1, Point p2)
{
    return std::sqrt(std::pow(p2.x*scalex-p1.x*scalex,2)+std::pow(p2.y*scaley-p1.y*scaley,2));
}

void Robomath::calcscale(Point p1, Point p2, double roborx, double robory)
{
    scalex = roborx/std::abs(p1.x-p2.x);
    scaley = robory/std::abs(p1.y-p2.y);
}

double Robomath::calcangle(Point p1, Point p2, Point p3)
{
    double a = calcrlength(p1,p2);
    double b = calcrlength(p2,p3);
    double c = calcrlength(p3,makeinvert(p1,p2));
    double sum = std::pow(a,2)+std::pow(b,2)-std::pow(c,2);
    return std::acos(sum/(2*a*b))*180/PI;
}

double Robomath::calcangle_noninvert(Point p1, Point p2, Point p3)
{
    double a = calcrlength(p1,p2);
    double b = calcrlength(p2,p3);
    double c = calcrlength(p3,p1);
    double sum = std::pow(a,2)+std::pow(b,2)-std::pow(c,2);
    return std::acos(sum/(2*a*b))*180/PI;
}


Point Robomath::calccenter(Point p1, Point p2)
{
    Point answer;
    if(p1.x > p2.x)
        answer.x = p2.x + (p1.x-p2.x)/2 - 10;
    else
        answer.x = p1.x + (p2.x-p1.x)/2 - 10;
    if(p1.y > p2.y)
        answer.y = p2.y + (p1.y-p2.y)/2;
    else
        answer.y = p1.y + (p2.y-p1.y)/2;
    return answer;
}

Point Robomath::makeinvert(Point p1, Point p2)
{
    Point answer;
    if(p2.x > p1.x)
        answer.x = p1.x + (p2.x - p1.x)*2;
    else if(p2.x < p1.x)
        answer.x = p1.x - (p1.x - p2.x)*2;
    if(p2.y > p1.y)
        answer.y = p1.y + (p2.y - p1.y)*2;
    else if(p2.y < p1.y)
        answer.y = p1.y - (p1.y - p2.y)*2;
    return answer;
}


Directions Robomath::calcdirection(Point p1, Point p2, Point p3)
{
    p1 = inverty(p1);
    p2 = inverty(p2);
    p3 = inverty(p3);
    Point pr1 = Point(p2.x+p2.y-p1.y,p2.y+p1.x-p2.x);
    Point pr2 = makeinvert(pr1,p2);
    double r1 = calcrlength(p3,pr1);
    double r2 = calcrlength(p3,pr2);
      if(r1>r2)
	return LEFT;
      else
	return RIGHT;
}

int Robomath::calcstepscmd(double rsize, Directions dir)
{
    switch( dir)
    {
      case LEFT:
	return (int)floor((rsize / sets->getlstepdegrees())+0.5);
      case RIGHT:
	return (int)floor((rsize / sets->getrstepdegrees())+0.5);
      case FORWARD:
	return (int)floor((rsize / sets->getfwstep())+0.5);
      case BACKWARD:
	return (int)floor((rsize / sets->getfwstep())+0.5);
    }
}

std::string Robomath::makecmd(Directions dir, int count)
{
    std::stringstream ss;
    switch(dir)
    {
      case LEFT:
      {
	for(int i=0;i<count;i++)
	  ss << "a";
	return ss.str();
      }
      case RIGHT:
      {
	for(int i=0;i<count;i++)
	  ss << "d";
	return ss.str();
      }
      case FORWARD:
      {
	for(int i=0;i<count;i++)
	  ss << "w";
	return ss.str();
      }
      case BACKWARD:
      {
	for(int i=0;i<count;i++)
	  ss << "s";
	return ss.str();
      }
    }
}

Point Robomath::inverty(Point p)
{
    return Point(p.x,imagesize.y-p.y);
}








