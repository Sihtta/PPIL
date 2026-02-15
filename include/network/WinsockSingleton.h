#ifndef WINSOCKSINGLETON_H
#define WINSOCKSINGLETON_H

#ifdef _WIN32
#include <winsock2.h>
#endif

class WinsockSingleton
{
public:
    static WinsockSingleton &instance();

private:
    WinsockSingleton();
    ~WinsockSingleton();

    WinsockSingleton(const WinsockSingleton &) = delete;
    WinsockSingleton &operator=(const WinsockSingleton &) = delete;
};

#endif
