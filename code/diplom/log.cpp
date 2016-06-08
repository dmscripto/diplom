#include "log.h"

void Log::printMessage(std::string message, Log::Tags tag)
{
    switch(tag)
    {
    case Log::ERROR:
        std::cout << "[ERROR] " << message << std::endl;
        break;
    case Log::INFO:
        std::cout << "[INFO] " << message << std::endl;
        break;
    case Log::WARNING:
        std::cout << "[WARNING] " << message << std::endl;
        break;
    default:
        std::cout << "[UNKNOWN] " << message << std::endl;
        break;
    }
}
