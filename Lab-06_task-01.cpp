#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    float salary;
public:
    Employee(string n, float s) : name(n), salary(s) {}
    virtual void displayDetails() {
        cout << "Name: " << name << "\nSalary: " << salary << endl;
    }
};

class Manager : public Employee {
    float bonus;
public:
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}
    void displayDetails() override {
        cout << "Name: " << name << "\nSalary: " << salary << "\nBonus: " << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;
    cout << "Enter Manager Name: ";
    getline(cin, name);
    cout << "Enter Salary: ";
    cin >> salary;
    cout << "Enter Bonus: ";
    cin >> bonus;
    
    Manager m(name, salary, bonus);
    m.displayDetails();
    
    return 0;
}
