#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("vehicles.txt"); 
    std::string line;

    if (!file.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    while (std::getline(file, line)) { 
        
        if (line.empty() || line[0] == '#') {
            continue;
        }
        std::cout << line << std::endl;  
    }

    file.close();  
    return 0;
}
