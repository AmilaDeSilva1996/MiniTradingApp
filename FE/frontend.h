#ifndef FRONTEND_H
#define FRONTEND_H

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")  // Link with Winsock library

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

void sendToGate(const std::string& message);

#endif // FRONTEND_H
