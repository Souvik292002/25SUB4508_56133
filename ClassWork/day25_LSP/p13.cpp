#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    std::string chr = "Bhima";
    std::string rchr;

    pid = fork();

    if (pid < 0) {
        std::cerr << "Unable to create child process" << std::endl;
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child Process: Writing to file
        std::ofstream outFile("test.dat");
        if (outFile.is_open()) {
            outFile << chr;
            std::cout << "Writing to the file is done!" << std::endl;
            std::cout << "Child is exiting" << std::endl;
            outFile.close();
        } else {
            std::cerr << "Unable to open file for writing" << std::endl;
            return EXIT_FAILURE;
        }
    } 
    else {
        // Parent Process: Reading from file
        wait(nullptr); // Uncomment this to ensure child finishes before parent reads
        
        std::ifstream inFile("test.dat");
        if (!inFile) {
            std::cerr << "Unable to open the input file" << std::endl;
            return EXIT_FAILURE;
        }

        if (inFile >> rchr) {
            std::cout << "Read string from the file = " << rchr << std::endl;
        }
        inFile.close();
    }

    std::cout << std::endl;
    return 0;
}