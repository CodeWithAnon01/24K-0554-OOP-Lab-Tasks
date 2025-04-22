#include <iostream>
#include <string>
using namespace std;


class Patient {
protected:
    string name;
    string id;

public:
    
    Patient(string name, string id) : name(name), id(id) {}

    
    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;

    
    virtual ~Patient() {}
};


class InPatient : public Patient {
public:
    
    InPatient(string name, string id) : Patient(name, id) {}

    
    void displayTreatment() override {
        cout << "Inpatient Treatment for " << name << " (ID: " << id << ").\n";
        cout << "Includes room, food, and medical expenses.\n";
    }

    
    void calculateCost() override {
        cout << "Inpatient cost calculation based on treatment, room, and services.\n";
    }
};


class OutPatient : public Patient {
public:
    
    OutPatient(string name, string id) : Patient(name, id) {}

    
    void displayTreatment() override {
        cout << "Outpatient Treatment for " << name << " (ID: " << id << ").\n";
        cout << "Includes consultation and follow-up.\n";
    }

    
    void calculateCost() override {
        cout << "Outpatient cost calculation based on consultation and follow-up visits.\n";
    }
};

int main() {
    
    Patient* p1 = new InPatient("John Doe", "IP123");
    Patient* p2 = new OutPatient("Jane Smith", "OP456");


    p1->displayTreatment();
    p1->calculateCost();
    cout << "\n";

    p2->displayTreatment();
    p2->calculateCost();

    delete p1;
    delete p2;

    return 0;
}


//Outputs
// Inpatient Treatment for John Doe (ID: IP123).
// Includes room, food, and medical expenses.
// Inpatient cost calculation based on treatment, room, and services.

// Outpatient Treatment for Jane Smith (ID: OP456).
// Includes consultation and follow-up.
// Outpatient cost calculation based on consultation and follow-up visits.
