#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <array>

// Function to execute a shell command and capture its output
std::string executeCommand(const std::string& command) {
    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

// Main function
int main() {
    try {
        // Run the `top` command in batch mode to capture output
        std::string command = "top -b -n 1"; // -b: batch mode, -n 1: one iteration
        std::string output = executeCommand(command);

        // Display the captured output (you can parse it further as needed)
        std::cout << "Top Output:\n" << output << std::endl;

        // Example: Parse and extract specific information (e.g., CPU usage)
        std::istringstream stream(output);
        std::string line;
        while (std::getline(stream, line)) {
            if (line.find("%Cpu(s):") != std::string::npos) {
                std::cout << "CPU Usage Line: " << line << std::endl;
                break;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

