#ifndef PATH_H
#define PATH_H

#include <opencv2/core.hpp>
#include "serial.h"
#include <vector>
#include <fstream>
#include "log.h"
#include <sstream>
#include "robomath.h"
#include "video.h"

class Path
{
  SerialControl* serial;
  Robomath* math;
  std::vector<std::string> cmds;  
  
public:
  Path(Robomath* math);
  virtual ~Path();
  virtual void initSerial(const char* port);
  virtual int addcmd(std::string& cmd);
  virtual int rmcmd(int index);
  virtual int createpath();
  virtual int buildpath(cv::Point center, std::vector< cv::Point > points, std::vector< cv::Point > dotpoints);
  virtual int readpath(const char* path = "path.dat");
  virtual int writepath(const char* path = "path.dat");
  virtual int pathcontroller(CamCapture* cam);
};

#endif