#include <iostream>
#include "video.h"
#include "pathDrawer.h"
#include "console.h"
#include "robomath.h"
#include "settings.h"

void mouseCallback(int event, int x, int y, int flags, void *param)
{
    PathDrawer* pd = static_cast<PathDrawer*>(param);
    pd->mouseCallback(event,x,y,flags);
}

int main(int argc, const char **argv) {

    Mat image = imread("plan.jpg",1);
    RobotSettings* sets = new RobotSettings();
    Robomath* math = new Robomath(sets,Point(image.cols, image.rows));
    PathDrawer* pd = new PathDrawer(image,sets,math);
    namedWindow("original",CV_WINDOW_AUTOSIZE);
    cvSetMouseCallback( "original", mouseCallback, (void*)pd);
    ConsoleControl consoleControl(argc,argv,sets,math,pd);
    if(consoleControl.parseCommands() == -1)
    {
      Log::printMessage("Main error!", Log::ERROR);
      return -1;
    }
    return 0;
}


