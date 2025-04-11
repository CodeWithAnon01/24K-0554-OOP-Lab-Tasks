#include <iostream>
using namespace std;

class Car;

class InventoryManager {
public:
    static void updatePrice(Car& car, double newPrice);
    static void display(const Car& car);
};

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

void InventoryManager::updatePrice(Car& car, double newPrice) {
    car.price = newPrice;
}

void InventoryManager::display(const Car& car) {
    cout << "Model: " << car.model << ", Price: $" << car.price << endl;
}

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c1.price < c2.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars have the same price." << endl;
}

int main() {
    Car car1("Sedan", 25000), car2("SUV", 30000);
    InventoryManager::display(car1);
    InventoryManager::updatePrice(car1, 26000);
    comparePrice(car1, car2);
    return 0;
}