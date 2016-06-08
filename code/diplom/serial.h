#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>
#include <stdio.h>      
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions

class SerialControl
{
    int sfile;
    struct termios tty;
  
public:
    SerialControl(const char* name = "/dev/rfcomm0");
    ~SerialControl();
    int writecmd(std::string cmd);
    std::string readanswer();
};

#endif