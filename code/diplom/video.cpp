#include "video.h"

CamCapture::CamCapture()
{
    counter = 0;
    stop = false;
}

CamCapture::~CamCapture()
{
    destroyWindow("capture");
}

int CamCapture::showVideo()
{
    capture.open("rtsp://admin:123456@192.168.43.12/live1.sdp"); //TODO: Добавить 2 камеру
    if(!capture.isOpened())
      return -1;
    //namedWindow("capture",CV_WINDOW_AUTOSIZE);
    //showFrame();
    return 0;
}

void CamCapture::showFrame()
{
    capture >> frame;
    imshow("capture", frame);
    key = cvWaitKey(30);
}


void CamCapture::saveFrame()
{
    if(!capture.isOpened())
    {
        std::cout << "Error! Cam is not opened" << std::endl;
    }
    capture >> frame;
    char filename[20];
    sprintf(filename, "Image%d.jpg", counter);
    cout << "capture... " <<  filename << endl;
    imwrite(filename, frame);
    counter++;
    //capture.release();
    //destroyWindow("capture");
}

void CamCapture::stopVideo()
{
    stop = true;
    capture.release();
}




