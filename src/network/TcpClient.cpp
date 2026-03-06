#include "network/TcpClient.h"
#include "network/WinsockSingleton.h"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <unistd.h>
#include <arpa/inet.h>
#endif

#include <iostream>

// Constructeur : initialise l'adresse du serveur et le port
TcpClient::TcpClient(const std::string &h, int p)
    : host(h), port(p)
{
#ifdef _WIN32
    sock = INVALID_SOCKET;
#else
    sock = -1;
#endif
}

// Destructeur : ferme la connexion si elle est ouverte
TcpClient::~TcpClient()
{
    close();
}

// Établit la connexion TCP avec le serveur
bool TcpClient::connectToServer()
{
    // Initialise Winsock sous Windows (via le Singleton)
    WinsockSingleton::instance();

    // Création de la socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

#ifdef _WIN32
    if (sock == INVALID_SOCKET)
        return false;
#else
    if (sock < 0)
        return false;
#endif

    // Configuration de l'adresse du serveur
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host.c_str());

    // Tentative de connexion au serveur
    if (connect(sock, (sockaddr *)&server, sizeof(server)) < 0)
        return false;

    return true;
}

// Envoie une ligne de texte au serveur
void TcpClient::sendLine(const std::string &line)
{
    std::string msg = line + "\n";
    send(sock, msg.c_str(), msg.size(), 0);
}

// Ferme la connexion TCP
void TcpClient::close()
{
#ifdef _WIN32
    if (sock != INVALID_SOCKET)
        closesocket(sock);
#else
    if (sock >= 0)
        ::close(sock);
#endif
}