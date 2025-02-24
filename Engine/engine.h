#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 9090
#define BUFFER_SIZE 1024

class engine {
public:
    engine();
    ~engine();

    void startServer();
    
private:
    WSADATA wsa;
    SOCKET serverSocket;
    struct sockaddr_in serverAddr;

    void handleClient(SOCKET clientSocket);
    void error(const std::string& msg);
};

#endif // ENGINE_H
