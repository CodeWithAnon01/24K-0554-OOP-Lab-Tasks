#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string type = "AutonomousCar";
    std::string extraData = "SW:4.5,CERT-AI";

    if (type == "AutonomousCar") {
        size_t pos = extraData.find("SW:");
        if (pos != std::string::npos) {
            std::string version = extraData.substr(pos + 3); 
            float softwareVersion = std::stof(version);  
            std::cout << "Software Version: " << softwareVersion << std::endl;
        }
    }
    else if (type == "ElectricVehicle") {
        size_t pos = extraData.find("Battery:");
        if (pos != std::string::npos) {
            std::string batteryCapacity = extraData.substr(pos + 8);  
            int battery = std::stoi(batteryCapacity);  
            std::cout << "Battery Capacity: " << battery << std::endl;
        }
    }

    return 0;
}
