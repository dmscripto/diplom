#ifndef VIDEO_H
#define VIDEO_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class CamCapture
{
    VideoCapture capture;
    double width, height;
    Mat frame;
    int counter;
    bool stop;
    char key;

  public:
    CamCapture();
    virtual ~CamCapture();
    int showVideo();
    virtual void showFrame();
    virtual void saveFrame();
    virtual void stopVideo();
};

#endif
