#ifndef CONSOLECONTROL_H
#define CONSOLECONTROL_H

#include <iostream>
#include <opencv2/core.hpp>
#include "settings.h"
#include "path.h"
#include "robomath.h"
#include "pathDrawer.h"
#include "video.h"

using namespace cv;

class ConsoleControl
{
    CommandLineParser* parser;
    RobotSettings* settings;
    Path* path;
    Robomath* math;
    PathDrawer* drawer;
    CamCapture* cam;
    
public:
    ConsoleControl(int argc, const char** argv, RobotSettings* sets, Robomath* math, PathDrawer* drawer);
    virtual int parseCommands();
    virtual void printHelp(bool error);
    virtual void printInfo();
};

#endif