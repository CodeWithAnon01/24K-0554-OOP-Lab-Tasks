#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;
public:
    Vehicle(string b, int s) : brand(b), speed(s) {}
    virtual void displayDetails() {
        cout << "Brand: " << brand << "\nSpeed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;
public:
    Car(string b, int s, int st) : Vehicle(b, s), seats(st) {}
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
    int batteryLife;
public:
    ElectricCar(string b, int s, int st, int bl) : Car(b, s, st), batteryLife(bl) {}
    void displayDetails() override {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " kWh" << endl;
    }
};

int main() {
    ElectricCar tesla("Tesla", 250, 5, 100);
    tesla.displayDetails();
    return 0;
}