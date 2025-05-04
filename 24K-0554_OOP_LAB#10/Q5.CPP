#include <iostream>
#include <string>

int main() {
    std::string type = "HybridTruck";
    std::string extraData = "Cargo:5000|Battery:75";

    if (type == "HybridTruck") {
        size_t posColon = extraData.find(":");
        size_t posPipe = extraData.find("|");

        if (posColon != std::string::npos && posPipe != std::string::npos) {
            std::string cargo = extraData.substr(posColon + 1, posPipe - posColon - 1); 
            int cargoValue = std::stoi(cargo); 

            std::string battery = extraData.substr(posPipe + 9); 
            int batteryValue = std::stoi(battery); 

            std::cout << "Cargo: " << cargoValue << ", Battery: " << batteryValue << std::endl;
        }
    }

    return 0;
}
