#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 8080
#define ENGINE_PORT 9090
#define BUFFER_SIZE 1024

void error(const char* msg) {
    std::cerr << msg << " Error Code: " << WSAGetLastError() << std::endl;
    exit(EXIT_FAILURE);
}

void forwardToEngine(const std::string& name) {
    SOCKET engineSocket;
    struct sockaddr_in engineAddr;
    char buffer[BUFFER_SIZE];

    engineSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (engineSocket == INVALID_SOCKET) error("Socket creation failed");

    engineAddr.sin_family = AF_INET;
    engineAddr.sin_port = htons(ENGINE_PORT);
    engineAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(engineSocket, (struct sockaddr*)&engineAddr, sizeof(engineAddr)) < 0) {
        error("Connection to Engine failed");
    }

    send(engineSocket, name.c_str(), name.length(), 0);
    recv(engineSocket, buffer, BUFFER_SIZE, 0);
    
    std::cout << "Engine Response: " << buffer << std::endl;
    
    closesocket(engineSocket);
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
    std::cout << "Gate Server is listening on port " << PORT << "...\n";

    while (true) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket == INVALID_SOCKET) error("Accept failed");

        recv(clientSocket, buffer, BUFFER_SIZE, 0);
        std::string name(buffer);
        std::cout << "Received from Frontend: " << name << std::endl;

        forwardToEngine(name);

        send(clientSocket, "Received & Processed", 20, 0);
        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
