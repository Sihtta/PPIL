#include "network/WinsockSingleton.h"

#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#endif

WinsockSingleton &WinsockSingleton::instance()
{
    static WinsockSingleton inst;
    return inst;
}

WinsockSingleton::WinsockSingleton()
{
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
}

WinsockSingleton::~WinsockSingleton()
{
#ifdef _WIN32
    WSACleanup();
#endif
}
