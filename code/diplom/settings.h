#ifndef ROBOTSETTINGS_H
#define ROBOTSETTINGS_H

#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include "log.h"

using namespace cv;

enum Params {
    RSIZE,
    FWSTEP,
    LSTEPDEGREES,
    RSTEPDEGREES,
    STEPTIME
};

class RobotSettings
{
    Point rsize;
    double fwstep;
    double lstepDegrees;
    double rstepDegrees;
    int steptime;
    
    const char* params[5] = {
        "RSIZE",
        "FWSTEP",
        "LSTEPDEGREES",
        "RSTEPDEGREES",
        "STEPTIME"
    };
    const int count=sizeof(params)/sizeof(char*);

public:
    RobotSettings();
    virtual ~RobotSettings();
    virtual int createSettings();
    virtual int printSettings();
    virtual int readSettings(const char* path = "settings.dat");
    virtual int writeSettings(const char* path = "settings.dat");
    template<typename T> int changeSetting(Params param, T value);
    
    int switchFunc(char* buf)
    {
        for(int i=0; i<count; ++i)
            if (!strcmp(buf,params[i]))
                return i;
        return -1;
    }
    
    virtual Point getrsize() { return rsize; }
    virtual double getfwstep() { return fwstep; }
    virtual double getlstepdegrees() { return lstepDegrees; }
    virtual double getrstepdegrees() { return rstepDegrees; }
    virtual double getsteptime() { return steptime; }
};

template<typename T>
int RobotSettings::changeSetting(Params param, T value)
{
    switch(param)
    {
    case RSIZE:
        rsize = static_cast<Point>(value);
        break;
    case FWSTEP:
        fwstep = static_cast<double>(value);
        break;
    case LSTEPDEGREES:
        lstepDegrees = static_cast<double>(value);
        break;
    case RSTEPDEGREES:
        rstepDegrees = static_cast<double>(value);
        break;
    case STEPTIME:
        steptime = static_cast<int>(value);
        break;
    default:
        return -1;
    }
    return 0;
}

#endif