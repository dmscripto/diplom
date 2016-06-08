#include "console.h"

ConsoleControl::ConsoleControl(int argc, const char** argv, RobotSettings* sets, Robomath* math, PathDrawer* drawer)
{
    parser = new CommandLineParser(argc,argv,
                                   "{help h usage ?||}""{info i||}"
                                   "{serial s|/dev/rfcomm0|}"
                                   "{settings-read s-r|<none>|}""{settings-write s-w|<none>|}"
                                   "{settings-create s-c||}""{settings-print s-p||}"
                                   "{path-read p-r|<none>|}""{path-write p-w|<none>|}"
                                   "{path-create p-c|<none>|}"
                                   "{run r||}"
                                  );
    this->settings = sets;
    this->math = math;
    this->drawer = drawer;
    path = new Path(math);
    cam = new CamCapture();
}

int ConsoleControl::parseCommands()
{
    bool mistake = true;
    if(parser->has("help"))
    {
        printHelp(false);
        return 0;
    }
    if(parser->has("info"))
    {
        printInfo();
        return 0;
    }
    if(parser->has("settings-read"))
    {
        settings = new RobotSettings();
        const char* value = parser->get<String>("settings-read").c_str();
        if(!strcmp("true",value))
            settings->readSettings();
        else
            settings->readSettings(value);
        mistake = false;
    }
    if(parser->has("settings-create"))
    {
        settings->createSettings();
        if(parser->has("settings-write"))
        {
            const char* value = parser->get<String>("settings-write").c_str();
            if(!strcmp("true",value))
                settings->writeSettings();
            else
                settings->writeSettings(value);
        }
        else
            settings->writeSettings();
        mistake = false;
    }
    if(parser->has("settings-write"))
    {
        const char* value = parser->get<String>("settings-write").c_str();
        if(!strcmp("true",value))
            settings->writeSettings();
        else
            settings->writeSettings(value);
        mistake = false;
    }
    if(parser->has("settings-print"))
    {
        settings->printSettings();
        mistake = false;
    }
    if(parser->has("path-read"))
    {
        const char* value = parser->get<String>("path-read").c_str();
        if(!strcmp("true",value))
            path->readpath();
        else
            path->readpath(value);
        mistake = false;
    }
    if(parser->has("path-create"))
    {
        const char* mode = parser->get<String>("path-create").c_str();
        if(!strcmp("true",mode))
            path->createpath();
        else if(!strcmp("g",mode))
        {
            imshow("original", drawer->getimage());
            while(true)
            {
                char key = cvWaitKey(0);
                if(key == 27) // esc
                    break;
                if(key == 100) // d
                    drawer->changeMod(DOTES);
                if(key == 102) // f
                    drawer->changeMod(FINDROBOT);
                if(key == 116) // t
                    drawer->changeMod(ANGLES);
            }
            path->buildpath(drawer->getcenter(),drawer->getpoints(),drawer->getdotpoints());
	    mistake = false;
        }
        else
            path->createpath();

        if(parser->has("path-write"))
        {
            const char* value = parser->get<String>("path-write").c_str();
            if(!strcmp("true",value))
                path->writepath();
            else
                path->writepath(value);
        }
        else
            path->writepath();
        mistake = false;
    }
    if(parser->has("path-write"))
    {
        const char* value = parser->get<String>("path-write").c_str();
        if(!strcmp("true",value))
            path->writepath();
        else
            path->writepath(value);
        mistake = false;
    }
    if(parser->has("run"))
    {
        path->initSerial(parser->get<String>("serial").c_str());
        cam->showVideo();
        path->pathcontroller(cam);
        cam->~CamCapture();
        mistake = false;
    }
    if(mistake)
        printHelp(true);
    return 0;
}

void ConsoleControl::printHelp(bool error)
{
    if(error)
        Log::printMessage("Usage Error!", Log::ERROR);
    std::cout << "This is automatic scanning robot system.\n"
              "Usage: robotvision --command=[value]\n"
              "--serial | s            : Set serial port. Default: '/dev/rfcomm0'\n"
              "--run | r               : Run robot controller\n"
              "--settings-create | s-c : Create robot parameters\n"
              "--settings-print | s-p  : Print robot parameters\n"
              "--settings-read | s-r   : Read robot parameters\n"
              "--settings-write | s-w  : Write robot parameters to file\n"
              "--path-create | p-c [g] : Create program path for the robot.\n"
              "--path-read | p-r       : Read path form file\n"
              "--path-write | p-w      : Write path to file. Default: 'path.dat'\n"
              "--info | i              : Print program info."
              << std::endl;
}

void ConsoleControl::printInfo()
{
    std::cout << "Version 1.1\n"
              "Writed by Postoyalkin D.S." << std::endl;
}




