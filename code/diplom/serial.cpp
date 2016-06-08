#include "serial.h"

SerialControl::SerialControl(const char* name)
{
    std::cout << name << std::endl;
    sfile = open(name, O_RDWR| O_NOCTTY);
    memset (&tty, 0, sizeof tty);
    if ( tcgetattr ( sfile, &tty ) != 0 )
        std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
    cfsetospeed (&tty, B9600);
    cfsetispeed (&tty, B9600);
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;
    tty.c_cflag     &=  ~CRTSCTS;           // no flow control
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines
    tty.c_iflag     &=  ~(IXON | IXOFF | IXANY);
    tty.c_lflag     &=  ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_oflag     &=  ~OPOST;
    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  0;                  // 0 seconds read timeout
    if ( tcsetattr ( sfile, TCSANOW, &tty ) != 0) {
        std::cout << "Error " << errno << " from tcsetattr" << std::endl;
    }
    /* Flush Port */
    tcflush( sfile, TCIFLUSH );
    sleep(3);
}

int SerialControl::writecmd(std::string cmd)
{
    int n_written = 0,
        spot = 0;

    do {
        n_written = write( sfile, &cmd[spot], 1 );
        spot += n_written;
    } while (cmd[spot-1] != '\r' && n_written > 0);
}

std::string SerialControl::readanswer()
{
    int n = 0, spot = 0;
    char buf = '\0';

    /* Whole response*/
    char response[1024];
    memset(response, '\0', sizeof response);
    do {
        n = read( sfile, &buf, 1 );
        sprintf( &response[spot], "%c", buf );
        spot += n;
    } while( buf != '\r' && n > 0);

    if (n < 0) {
        return strcat("Error reading: ",strerror(errno));
    }
    else if (n == 0) {
        return "Read nothing!";
    }
    else {
        return strcat("Response: ",response);
    }
}


