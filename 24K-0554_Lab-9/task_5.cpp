#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string trackingNumber, double weight) : trackingNumber(trackingNumber), weight(weight) {}

    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;

    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string trackingNumber, double weight) : Shipment(trackingNumber, weight) {}

    void estimateDeliveryTime() override {
        cout << "Estimating delivery time for AirFreight: " << trackingNumber << endl;
        cout << "Air shipment takes approximately 3 days." << endl;
    }

    void showDetails() override {
        cout << "Air Freight Tracking Number: " << trackingNumber << ", Weight: " << weight << "kg" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string trackingNumber, double weight) : Shipment(trackingNumber, weight) {}

    void estimateDeliveryTime() override {
        cout << "Estimating delivery time for GroundShipment: " << trackingNumber << endl;
        cout << "Ground shipment takes approximately 7 days." << endl;
    }

    void showDetails() override {
        cout << "Ground Shipment Tracking Number: " << trackingNumber << ", Weight: " << weight << "kg" << endl;
    }
};

int main() {
    Shipment* shipment1 = new AirFreight("AF123456", 15.5);
    Shipment* shipment2 = new GroundShipment("GS654321", 25.3);

    shipment1->showDetails();
    shipment1->estimateDeliveryTime();
    cout << endl;

    shipment2->showDetails();
    shipment2->estimateDeliveryTime();

    delete shipment1;
    delete shipment2;

    return 0;
}


// Output
// Air Freight Tracking Number: AF123456, Weight: 15.5kg
// Estimating delivery time for AirFreight: AF123456
// Air shipment takes approximately 3 days.

// Ground Shipment Tracking Number: GS654321, Weight: 25.3kg
// Estimating delivery time for GroundShipment: GS654321
// Ground shipment takes approximately 7 days.
