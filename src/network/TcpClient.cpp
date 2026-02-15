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

TcpClient::TcpClient(const std::string &h, int p)
    : host(h), port(p)
{
#ifdef _WIN32
    sock = INVALID_SOCKET;
#else
    sock = -1;
#endif
}

TcpClient::~TcpClient()
{
    close();
}

bool TcpClient::connectToServer()
{
    WinsockSingleton::instance();

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        return false;

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host.c_str());

    if (connect(sock, (sockaddr *)&server, sizeof(server)) < 0)
        return false;

    return true;
}

void TcpClient::sendLine(const std::string &line)
{
    std::string msg = line + "\n";
    send(sock, msg.c_str(), msg.size(), 0);
}

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
