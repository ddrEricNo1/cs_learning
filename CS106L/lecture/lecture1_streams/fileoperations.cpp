#include <iostream>
#include <fstream>

int main() {
    std::string filepath = "test.txt";
    std::ofstream outputFile(filepath);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl;
        return 1;
    }

    outputFile << "Hello world!" << std::endl;
    outputFile << "This is a new line" << std::endl;

    outputFile.close();

    return 0;
}
