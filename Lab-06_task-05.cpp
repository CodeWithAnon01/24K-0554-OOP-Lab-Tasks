#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;
public:
    Device(int id, bool s) : deviceID(id), status(s) {}
    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "Active" : "Inactive") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float screenSize;
public:
    SmartPhone(int id, bool s, float sz) : Device(id, s), screenSize(sz) {}
    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << "\"" << endl;
    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int id, bool s, bool hrm) : Device(id, s), heartRateMonitor(hrm) {}
    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
    int stepCounter;
public:
    SmartWearable(int id, bool s, float sz, bool hrm, int sc) 
        : Device(id, s), SmartPhone(id, s, sz), SmartWatch(id, s, hrm), stepCounter(sc) {}
    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << "\"\nHeart Rate Monitor: " 
             << (heartRateMonitor ? "Yes" : "No") << "\nStep Counter: " << stepCounter << endl;
    }
};

int main() {
    SmartWearable wearable(101, true, 1.5, true, 5000);
    wearable.displayDetails();
    return 0;
}