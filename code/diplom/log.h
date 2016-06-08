#ifndef LOG_H
#define LOG_H

#include <iostream>

class Log
{

public:
    enum Tags
    {
        ERROR,
        WARNING,
        INFO
    };
    static void printMessage(std::string message, Log::Tags tag);
    
};

#endif
