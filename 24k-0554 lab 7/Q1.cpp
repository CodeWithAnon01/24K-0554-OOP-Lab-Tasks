#include <iostream>
#include <cstring>

using namespace std;

class Device {
protected:
    int deviceID;
    char deviceName[50];
    bool status;

public:
    Device(int id, const char* name) {
        deviceID = id;
        strcpy(deviceName, name);
        status = false;
    }

    void turnOn() {
        status = true;
        cout << deviceName << " is now ON.\n";
    }

    void turnOff() {
        status = false;
        cout << deviceName << " is now OFF.\n";
    }

    void getStatus() {
        cout << deviceName << " is " << (status ? "ON" : "OFF") << ".\n";
    }

    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << ", Name: " << deviceName << "\n";
    }
};

class Light : public Device {
private:
    int brightnessLevel;
    char colorMode[20];

public:
    Light(int id, const char* name, int brightness, const char* color) 
        : Device(id, name), brightnessLevel(brightness) {
        strcpy(colorMode, color);
    }

    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << ", Color Mode: " << colorMode << "\n";
    }
};

class Thermostat : public Device {
private:
    float temperature;
    char mode[20];

public:
    Thermostat(int id, const char* name, float temp, const char* modeType) 
        : Device(id, name), temperature(temp) {
        strcpy(mode, modeType);
    }

    void getStatus() {
        cout << deviceName << " is set to " << temperature << "°C in " << mode << " mode.\n";
    }
};

class SecurityCamera : public Device {
private:
    int resolution;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, const char* name, int res, bool nightVision) 
        : Device(id, name), resolution(res), nightVisionEnabled(nightVision) {}

    void turnOn() {
        Device::turnOn();
        cout << "Security Camera is now recording.\n";
    }
};

class SmartPlug : public Device {
private:
    int powerConsumption;

public:
    SmartPlug(int id, const char* name, int power) 
        : Device(id, name), powerConsumption(power) {}

    void turnOff() {
        Device::turnOff();
        cout << "Power usage logged: " << powerConsumption << "W.\n";
    }
};

int main() {
    Light light(1, "Bedroom Light", 75, "Warm White");
    Thermostat thermostat(2, "Living Room Thermostat", 22.5, "Heating");
    SecurityCamera camera(3, "Front Door Camera", 1080, true);
    SmartPlug plug(4, "TV Smart Plug", 50);

    light.turnOn();
    light.displayInfo();
    
    thermostat.getStatus();
    
    camera.turnOn();
    
    plug.turnOff();

    return 0;
}
