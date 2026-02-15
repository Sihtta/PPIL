#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>

class TcpClient
{
public:
    TcpClient(const std::string &host, int port);
    ~TcpClient();

    bool connectToServer();
    void sendLine(const std::string &line);
    void close();

private:
#ifdef _WIN32
    SOCKET sock;
#else
    int sock;
#endif
    std::string host;
    int port;
};

#endif
