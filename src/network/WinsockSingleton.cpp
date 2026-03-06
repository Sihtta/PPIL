#include "network/WinsockSingleton.h"

#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib") // Lie automatiquement la bibliothèque Winsock sous Windows
#endif

// Retourne l'unique instance du singleton
WinsockSingleton &WinsockSingleton::instance()
{
    static WinsockSingleton inst;
    return inst;
}

// Constructeur : initialise la bibliothèque Winsock sous Windows
WinsockSingleton::WinsockSingleton()
{
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
}

// Destructeur : libère la bibliothèque Winsock
WinsockSingleton::~WinsockSingleton()
{
#ifdef _WIN32
    WSACleanup();
#endif
}