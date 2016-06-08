#include "path.h"

Path::Path(Robomath* math)
{
    cmds.reserve(10);
    this->math = math;
}

Path::~Path()
{
    delete &cmds;
    delete &serial;
}

void Path::initSerial(const char* port)
{
    serial = new SerialControl(port);
}


int Path::addcmd(std::string& cmd)
{
    cmds.insert(cmds.end(),cmd);
    return 0;
}

int Path::rmcmd(int index) {
    return 0;
}

int Path::createpath()
{
    Log::printMessage("Enter commands by lines. Write exit to end.", Log::INFO);
    std::string cmd;
    std::string value;
    std::stringstream ss;
    while (true)
    {
        std::cout << "Enter command: ";
        std::cin >> cmd;
        if(!strcmp("exit",cmd.c_str()))
            break;
        cmds.push_back(cmd);
        ss.str(std::string());
        ss.clear();
        ss << "Command: " << cmds.at(cmds.size()-1);
        Log::printMessage(ss.str(), Log::INFO);
    }
    Log::printMessage("Path created", Log::INFO);
    return 0;
}

int Path::buildpath(cv::Point center, std::vector< cv::Point > points, std::vector< cv::Point > dotpoints)
{
    bool calc = false;
    for(int i=1; i<points.size(); i++)
    {
        cmds.push_back(math->makecmd(FORWARD,math->calcstepscmd(math->calcrlength(points.at(i-1),points.at(i)),FORWARD)));
        for(int j=0; j<dotpoints.size(); j++)
            if(dotpoints.at(j).x == points.at(i).x && dotpoints.at(j).y == points.at(i).y)
            {
                double angle = math->calcangle(points.at(i-1),points.at(i),center);
                Directions dir = math->calcdirection(points.at(i-1),points.at(i),center);
                cmds.push_back(math->makecmd(dir, math->calcstepscmd(angle,dir)));
                cmds.push_back("picture");

                if(points.size() >= i+2)
                {
                    angle = math->calcangle_noninvert(center,points.at(i),points.at(i+1));
                    dir = math->calcdirection(points.at(i),center,points.at(i+1));
                    cmds.push_back(math->makecmd(dir, math->calcstepscmd(angle,dir)));
                }
                calc = true;
                break;
            }
        if(!calc && points.size() >= i+2)
        {
            double angle = math->calcangle(points.at(i-1),points.at(i),points.at(i+1));
            Directions dir = math->calcdirection(points.at(i-1),points.at(i),points.at(i+1));
            cmds.push_back(math->makecmd(dir,math->calcstepscmd(angle,dir)));

        }
        calc = false;
    }
    Log::printMessage("The path is built", Log::INFO);
    return 0;
}


int Path::pathcontroller(CamCapture* cam)
{
    if(cmds.size()==0)
    {
        Log::printMessage("Commands vector is empty!", Log::ERROR);
        return -1;
    }
    std::string answer;
    std::stringstream ss;
    std::string cmd;
    for(int i=0; i<cmds.size(); i++)
    {
        ss.str(std::string());
        ss.clear();
        ss << "Send " << i+1 << " command: " << cmds[i] << std::endl;
        cmd = ss.str();
        Log::printMessage(cmd,Log::INFO);
        cmd = cmds[i];
        if(!strcmp("capture",cmd.c_str()))
            cam->saveFrame();
        else
            serial->writecmd(cmd);
        //answer = serial->readanswer();
        //Log::printMessage(answer.insert(0,"Answer: "),Log::INFO); //TODO: Проверить получение
    }
    Log::printMessage("The end point is reached", Log::INFO);
    return 0;
}

int Path::readpath(const char* path)
{
    char* buff = new char[30];
    std::ifstream fin(path, std::ios_base::in);
    if(!fin.is_open())
    {
        Log::printMessage("Can't open path file!", Log::ERROR);
        return -1;
    }
    for(int i=0; i<10; i++)
    {
        fin >> buff;
        if(!strcmp(buff,""))
            break;
        cmds.insert(cmds.end(),buff);
    }
    fin.close();
    Log::printMessage("Path read successfully ", Log::INFO);
    return 0;
}


int Path::writepath(const char* path)
{
    if(cmds.size()==0)
    {
        Log::printMessage("Commands vector is empty! Not saved.", Log::ERROR);
        return -1;
    }
    std::ofstream fout(path, std::ios_base::trunc);
    if(!fout.is_open())
    {
        Log::printMessage("Can't open path file!", Log::ERROR);
        return -1;
    }
    for(int i=0; i<cmds.size(); i++)
        fout << cmds[i] << std::endl;
    fout.close();
    Log::printMessage("Path saved", Log::INFO);
    return 0;
}





