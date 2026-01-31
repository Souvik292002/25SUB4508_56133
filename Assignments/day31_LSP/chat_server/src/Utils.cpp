#include "Utils.h"
#include <iostream>

void printError(const std::string& msg) {
    std::cerr << "[ERROR] " << msg << std::endl;
}

void printInfo(const std::string& msg) {
    std::cout << "[INFO] " << msg << std::endl;
}
