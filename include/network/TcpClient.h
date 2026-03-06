#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>

#ifdef _WIN32
#include <winsock2.h>
#endif

/// Client TCP utilisé pour communiquer avec le serveur Java de dessin
class TcpClient
{
public:
    /// Constructeur : initialise l'adresse du serveur et le port
    TcpClient(const std::string &host, int port);

    /// Destructeur : ferme la connexion si elle est ouverte
    ~TcpClient();

    /// Établit la connexion avec le serveur
    bool connectToServer();

    /// Envoie une ligne de texte au serveur
    void sendLine(const std::string &line);

    /// Ferme la connexion
    void close();

private:
#ifdef _WIN32
    SOCKET sock; /// socket utilisée sous Windows (Winsock)
#else
    int sock; /// socket utilisée sous Linux / Unix
#endif
    std::string host; /// adresse du serveur
    int port;         /// port du serveur
};

#endif