#include <iostream>
#include <fstream>
#include <sstream>
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

        std::stringstream ss(line);  
        std::string type, id, name, year, extraData, certification;

        std::getline(ss, type, ',');
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, year, ',');
        std::getline(ss, extraData, ',');
        std::getline(ss, certification);

        std::cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << ", ExtraData: " << extraData << ", Certification: " << certification << std::endl;
    }

    file.close();
    return 0;
}
