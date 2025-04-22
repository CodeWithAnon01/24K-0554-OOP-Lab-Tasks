#include <iostream>
#include <string>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading data from thermometer: Temperature data.\n";
    }

    void displayReport() override {
        cout << "Displaying report from thermometer: Temperature Report.\n";
    }
};

class Barometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading data from barometer: Pressure data.\n";
    }

    void displayReport() override {
        cout << "Displaying report from barometer: Pressure Report.\n";
    }
};

int main() {
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor1->displayReport();
    cout << endl;

    sensor2->readData();
    sensor2->displayReport();

    delete sensor1;
    delete sensor2;

    return 0;
}

// Outputs
// Reading data from thermometer: Temperature data.
// Displaying report from thermometer: Temperature Report.

// Reading data from barometer: Pressure data.
// Displaying report from barometer: Pressure Report.
