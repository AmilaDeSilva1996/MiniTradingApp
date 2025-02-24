#include "frontend.h"

int main() {
    std::string name;
    std::cout << "Enter the name: ";
    std::cin >> name;
    sendToGate(name);
    return 0;
}
