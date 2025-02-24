#include "engine.h"

engine::engine() {
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        error("WSAStartup failed");
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        error("Socket creation failed");
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        error("Binding failed");
    }
}

engine::~engine() {
    closesocket(serverSocket);
    WSACleanup();
}

void engine::startServer() {
    listen(serverSocket, 3);
    std::cout << "Engine Server is listening on port " << PORT << "...\n";

    struct sockaddr_in clientAddr;
    int addrLen = sizeof(clientAddr);
    
    while (true) {
        SOCKET clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket == INVALID_SOCKET) {
            error("Accept failed");
        }

        handleClient(clientSocket);
        closesocket(clientSocket);
    }
}

void engine::handleClient(SOCKET clientSocket) {
    char buffer[BUFFER_SIZE] = {0};
    recv(clientSocket, buffer, BUFFER_SIZE, 0);

    std::string receivedName(buffer);
    std::cout << "Processing: " << receivedName << std::endl;

    std::string response = "Processed: " + receivedName;
    send(clientSocket, response.c_str(), response.length(), 0);
}

void engine::error(const std::string& msg) {
    std::cerr << msg << " Error Code: " << WSAGetLastError() << std::endl;
    exit(EXIT_FAILURE);
}
