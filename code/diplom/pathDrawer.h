#ifndef PATHDRAWER_H
#define PATHDRAWER_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "log.h"
#include "robomath.h"
#include "settings.h"

using namespace cv;

enum Modes 
    {
      VIEW,
      DOTES,
      PATH,
      FINDROBOT,
      ANGLES
    };

class PathDrawer
{
    Mat image;
    Mat tmpimage;
    Robomath* math;
    RobotSettings* sets;
    bool isfirstclick;
    bool iscenterdot;
    bool isfirstrect;
    bool isscalesset;
    Modes mod;
    std::vector<Point> points;
    std::vector<Point> dotpoints;
    Point center, rect;
    
private:
    void update();
    void save();

public:
  
    PathDrawer(Mat image, RobotSettings* settings, Robomath* math);
    virtual ~PathDrawer();
    virtual void drawPath(Point point1, Point point2, CvScalar color = CV_RGB(250,0,0), int type = 8);
    virtual void drawCirclePath(Point point, int radius);
    virtual void mouseCallback(int event, int x, int y, int flags);
    virtual bool checklinking(Point& point, int indent = 5);
    virtual void drawText(std::string text, Point p);
    int setDot(Point& p);
    void changeMod(Modes mod);
    std::vector<Point> getpoints() { return points; }
    std::vector<Point> getdotpoints() { return dotpoints; }
    Point getcenter() { return center; }
    Mat getimage() { return image; }
};

#endif




