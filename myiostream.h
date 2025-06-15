#ifndef MYIOSTREAM_H
#define MYIOSTREAM_H

#include <unistd.h>
#include <cstdio>
#include <cstdlib>

class myios {
protected:
    int fd;
public:
    myios(int fd) : fd(fd) {}
};

class myostream : virtual public myios {
public:
    myostream(int fd = 1) : myios(fd) {}

    myostream& operator<<(const char* str) {
        while (*str) write(fd, str++, 1);
        return *this;
    }

    myostream& operator<<(char ch) {
        write(fd, &ch, 1);
        return *this;
    }

    myostream& operator<<(int num) {
        char buf[20];
        int len = sprintf(buf, "%d", num);
        write(fd, buf, len);
        return *this;
    }
};

class myistream : virtual public myios {
public:
    myistream(int fd = 0) : myios(fd) {}

    myistream& operator>>(int& x) {
        char buf[32];
        int i = 0;
        char ch;
        while (read(fd, &ch, 1) > 0 && ch != ' ' && ch != '\n') {
            buf[i++] = ch;
        }
        buf[i] = '\0';
        x = atoi(buf);
        return *this;
    }

    myistream& operator>>(char* str) {
        char ch;
        int i = 0;
        while (read(fd, &ch, 1) > 0 && ch != ' ' && ch != '\n') {
            str[i++] = ch;
        }
        str[i] = '\0';
        return *this;
    }
};

class myiostream : public myistream, public myostream {
public:
    myiostream(int fd) : myios(fd), myistream(fd), myostream(fd) {}
};

extern myiostream mycin;
extern myiostream mycout;

#endif