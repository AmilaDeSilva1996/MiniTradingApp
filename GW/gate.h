#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 8080
#define ENGINE_PORT 9090
#define BUFFER_SIZE 1024

class GateServer {
public:
    GateServer();
    ~GateServer();
    void start();

private:
    void error(const char* msg);
    void forwardToEngine(const std::string& name);

    SOCKET serverSocket;
    struct sockaddr_in serverAddr;
};

#endif // GATE_H
