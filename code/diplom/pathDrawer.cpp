#include "pathDrawer.h"

PathDrawer::PathDrawer(Mat image, RobotSettings* settings, Robomath* math)
{
    this->image = image;
    image.copyTo(tmpimage);
    isfirstclick = true;
    iscenterdot = true;
    isfirstrect = true;
    mod = PATH;
    this->math = math;
    this->sets = settings;
    isscalesset = false;
}

PathDrawer::~PathDrawer()
{
    delete &image;
    delete &tmpimage;
}

void PathDrawer::drawPath(Point point1, Point point2, CvScalar color, int type)
{
    line(tmpimage, point1, point2, color, 1, type);
}

void PathDrawer::drawCirclePath(Point point, int radius)
{
    circle(tmpimage, point, radius, CV_RGB(0,250,0),2,8);
}

void PathDrawer::mouseCallback(int event, int x, int y, int flags)
{
    switch( event )
    {
    case CV_EVENT_MOUSEMOVE:
    {
        switch (mod)
        {
        case PATH:
        {
            if(!isfirstclick)
            {
                image.copyTo(tmpimage);
                drawPath(points.at(points.size()-1),Point(x,y));
                if(isscalesset)
                {
                    Point p(x,y);
                    double val = math->calcrlength(points.at(points.size()-1),p);
                    std::ostringstream strs;
                    strs.precision(1);
                    strs << std::fixed << val <<"cm";
                    drawText(strs.str(),math->calccenter(points.at(points.size()-1),p));
                }
                imshow("original", tmpimage);
            }
        }
        break;
        case FINDROBOT:
        {
            if(!isfirstrect)
            {
                image.copyTo(tmpimage);
                rectangle(tmpimage, rect,Point(x,y),CV_RGB(0,0,250),2,8);
                imshow("original", tmpimage);
            }
        }
        break;
        case ANGLES:
        {
	    imshow("original", tmpimage);
        }
        break;
        default:
            update();
            break;
        }
    }
    break;
    case CV_EVENT_LBUTTONDOWN:
    {
        switch (mod)
        {
        case DOTES:
        {
            if(iscenterdot)
            {
                center = Point(x,y);
                drawCirclePath(center,2);
                save();
                iscenterdot = false;
            }
            else
            {
                Point p(x,y);
                if(setDot(p) != -1)
                {
                    drawCirclePath(dotpoints.at(dotpoints.size()-1),2);
                    save();
                }
            }
        }
        break;
        case PATH:
        {
            if(isfirstclick)
            {
                std::cout << "First point: " << x << " x " << y << std::endl;
                points.push_back(Point(x,y));
                isfirstclick = false;
            }
            else
            {
                std::cout << "Next point: " << x << " x " << y << std::endl;
                drawPath(points.at(points.size()-1), Point(x,y));
                tmpimage.copyTo(image);
                points.push_back(Point(x,y));
            }
        }
        break;
        case FINDROBOT:
        {
            if(isfirstrect)
            {
                rect = Point(x,y);
                isfirstrect = false;
            }
            else
            {
                Point rsize = sets->getrsize();
                math->calcscale(rect,Point(x,y),rsize.x,rsize.y);
                isscalesset = true;
                Log::printMessage("Scales set", Log::INFO);
                changeMod(VIEW);
            }
        }
        break;
        }
    }
    break;
    case CV_EVENT_LBUTTONUP:
        break;
    case CV_EVENT_RBUTTONDOWN:
    {
        image.copyTo(tmpimage);
        imshow("original", tmpimage);
        if(mod == VIEW)
            changeMod(PATH);
        else
            changeMod(VIEW);
    }
    break;
    }
}

void PathDrawer::changeMod(Modes mod)
{
    switch (mod)
    {
    case VIEW:
    {
        this->mod = VIEW;
        Log::printMessage("Mode changed to VIEW", Log::INFO);
    }
    break;
    case PATH:
    {
        this->mod = PATH;
        Log::printMessage("Mode changed to PATH", Log::INFO);
    }
    break;
    case DOTES:
    {
        if(this->mod != DOTES)
        {
            this->mod = DOTES;
            Log::printMessage("DOTES mode ON", Log::INFO);
        }
        else
        {
            this->mod = VIEW;
            Log::printMessage("DOTES mode OFF", Log::INFO);
            Log::printMessage("Mode changed to VIEW", Log::INFO);
        }
    }
    break;
    case FINDROBOT:
    {
        this->mod = FINDROBOT;
        Log::printMessage("FINDROBOT mod ON", Log::INFO);
        Log::printMessage("Select robot", Log::INFO);
    }
    break;
    case ANGLES:
    {
        if(this->mod != ANGLES)
        {
            this->mod = ANGLES;
            image.copyTo(tmpimage);
            for(int i=0; i<dotpoints.size(); i++)
            {
                drawPath(center,dotpoints.at(i),CV_RGB(0,250,0),8);
            }
            imshow("original", tmpimage);
            Log::printMessage("ANGLES mod ON", Log::INFO);
        }
        else
        {
	    update();
            Log::printMessage("ANGLES mod OFF", Log::INFO);
            changeMod(VIEW);
        }
    }
    break;
    }
}

int PathDrawer::setDot(Point& p)
{
    if(points.size() == 0)
        return -1;
    for(int i=0; i<points.size(); i++)
        if(std::abs(p.x - points.at(i).x) < 5 && std::abs(p.y - points.at(i).y) < 5)
        {
            Log::printMessage("Point located", Log::INFO);
            dotpoints.push_back(points.at(i));
            return i;
        }
    return -1;
}


bool PathDrawer::checklinking(Point& point, int indent)
{
    if(points.size() < 2)
        return false;
    Point* p = &points.at(points.size()-1);
    if(std::abs(point.x-p->x)<indent || std::abs(point.y-p->y)<indent)
        return true;
    else
        return false;
}

void PathDrawer::drawText(std::string text, Point p)
{
    putText(tmpimage, text, p, FONT_HERSHEY_SIMPLEX,0.3, CV_RGB(0, 0, 250));
}


void PathDrawer::update()
{
    image.copyTo(tmpimage);
    imshow("original", tmpimage);
}

void PathDrawer::save()
{
    tmpimage.copyTo(image);
    imshow("original", image);
}




