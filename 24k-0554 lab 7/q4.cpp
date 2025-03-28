#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
public:
    Person(string n, int a, string c) : name(n), age(a), contactNumber(c) {}
    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber << "\n";
    }
};

class Patient : public Person {
    int patientID;
    string medicalHistory;
    string doctorAssigned;
public:
    Patient(string n, int a, string c, int id, string history, string doctor)
        : Person(n, a, c), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory << "\nDoctor: " << doctorAssigned << "\n";
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
public:
    Doctor(string n, int a, string c, string spec, double fee)
        : Person(n, a, c), specialization(spec), consultationFee(fee) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nFee: " << consultationFee << "\n";
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string c, string ward, string shift)
        : Person(n, a, c), assignedWard(ward), shiftTimings(shift) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Ward: " << assignedWard << "\nShift: " << shiftTimings << "\n";
    }
};

class Administrator : public Person {
    string department;
    double salary;
public:
    Administrator(string n, int a, string c, string dept, double sal)
        : Person(n, a, c), department(dept), salary(sal) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary << "\n";
    }
};

int main() {
    Patient p1("John Doe", 45, "123-456-789", 1001, "Diabetes", "Dr. Smith");
    Doctor d1("Dr. Smith", 50, "987-654-321", "Cardiology", 200.0);
    Nurse n1("Alice Brown", 30, "567-890-123", "ICU", "Night");
    Administrator a1("Bob White", 40, "345-678-901", "Finance", 5000.0);
    
    p1.displayInfo();
    d1.displayInfo();
    n1.displayInfo();
    a1.displayInfo();
    
    return 0;
}
