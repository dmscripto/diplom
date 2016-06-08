#include "settings.h"

RobotSettings::RobotSettings()
{
    rsize = Point(40,40); 
    fwstep = 10; // cm
    lstepDegrees = 5;
    rstepDegrees = 5;
    steptime = 100;
}

RobotSettings::~RobotSettings()
{
    delete[] &params;
    delete &rsize;
}

int RobotSettings::createSettings()
{
    Log::printMessage("Set settings.", Log::INFO);
    std::cout << "Robot size [x y]: ";
    double x,y;
    std::cin >> x >> y;
    rsize = Point(x,y);
    std::cout << "Forward step [cm]: ";
    std::cin >> fwstep;
    std::cout << "Left step degrees: ";
    std::cin >> lstepDegrees;
    std::cout << "Right step degrees: ";
    std::cin >> rstepDegrees;
    std::cout << "Step time [mc]: ";
    std::cin >> steptime;
    return 0;
}

int RobotSettings::printSettings()
{
    Log::printMessage("Robot settings:\n", Log::INFO);
    std::cout << "Robot size [x y]:" << rsize.x << " x " << rsize.y << "\n"
		 "Forward step [cm]: " << fwstep << "\n"
		 "Left step degrees: " << lstepDegrees << "\n"
		 "Right step degrees: " << rstepDegrees << "\n"
		 "Step time [mc]: " << steptime << std::endl;
    return 0;
}



int RobotSettings::readSettings(const char* path)
{
    char* buff = new char[30];
    std::ifstream fin(path, std::ios_base::in);
    if(!fin.is_open())
    {
        Log::printMessage("Can't open settings file!", Log::ERROR);
        return -1;
    }
    for(int i=0;i<5;i++)
    {
        fin >> buff;
        switch(switchFunc(buff))
        {
        case RSIZE:
        {
            int x,y;
            fin >> x >> y;
            rsize = Point(x,y);
        }
        break;
        case FWSTEP:
            fin >> fwstep;
            break;
        case LSTEPDEGREES:
            fin >> lstepDegrees;
            break;
        case RSTEPDEGREES:
            fin >> rstepDegrees;
            break;
        case STEPTIME:
            fin >> steptime;
            break;
        }
    }
    fin.close();
    Log::printMessage("Settings read successfully ", Log::INFO);
    return 0;
}

int RobotSettings::writeSettings(const char* path)
{
    std::ofstream fout(path,std::ios_base::out);
    if(!fout.is_open())
    {
        Log::printMessage("Can't open settings file!", Log::INFO);
        return -1;
    }
    fout << params[0] << " " << rsize.x << " " << rsize.y << std::endl;
    fout << params[1] << " " << fwstep << std::endl;
    fout << params[2] << " " << lstepDegrees << std::endl;
    fout << params[3] << " " << rstepDegrees << std::endl;
    fout << params[4] << " " << steptime << std::endl;
    fout.close();
    Log::printMessage("Settings saved", Log::INFO);
    return 0;
}