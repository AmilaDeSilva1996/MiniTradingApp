#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#define __STDC_WANT_LIB_EXT1__ 1
#define  __STDC_LIB_EXT1__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 9090
#define BUFFER_SIZE 1024

void error(const char* msg) {
    std::cerr << msg << " Error Code: " << WSAGetLastError() << std::endl;
    exit(EXIT_FAILURE);
}

int main() {
    
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) error("Socket creation failed");

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        error("Binding failed");

    listen(serverSocket, 3);
    std::cout << "Engine Server is listening on port " << PORT << "...\n";

    while (true) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket == INVALID_SOCKET) error("Accept failed");

        recv(clientSocket, buffer, BUFFER_SIZE, 0);
        std::string receivedName(buffer);
        std::cout << "Processing: " << receivedName << std::endl;

        std::string response = "Processed: " + receivedName;
        send(clientSocket, response.c_str(), response.length(), 0);
        
        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
