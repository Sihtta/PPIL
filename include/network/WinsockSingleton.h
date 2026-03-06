#ifndef WINSOCKSINGLETON_H
#define WINSOCKSINGLETON_H

#ifdef _WIN32
#include <winsock2.h>
#endif

/// Singleton chargé d'initialiser et nettoyer la bibliothèque Winsock sous Windows
class WinsockSingleton
{
public:
    /// Retourne l'instance unique du singleton
    static WinsockSingleton &instance();

private:
    /// Constructeur : initialise Winsock
    WinsockSingleton();

    /// Destructeur : libère Winsock
    ~WinsockSingleton();

    // Empêche la copie du singleton
    WinsockSingleton(const WinsockSingleton &) = delete;
    WinsockSingleton &operator=(const WinsockSingleton &) = delete;
};

#endif