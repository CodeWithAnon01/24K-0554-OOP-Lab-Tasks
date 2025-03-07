
#include <iostream>
using namespace std;

struct Employee {
    string name;
    string designation;
};

class Project {
    string title;
    string deadline;
    Employee** employees;  // Pointer to array of pointers
    int maxEmployees;
    int numEmployees = 0;

public:
    Project(string t, string d, int max = 10) : title(t), deadline(d), maxEmployees(max) {
        employees = new Employee*[max];
    }

    void addEmployee(Employee* emp) {
        if(numEmployees < maxEmployees) {
            employees[numEmployees++] = emp;
        }
    }

    void display() {
        cout << "Project: " << title << "\nDeadline: " << deadline << "\nEmployees:\n";
        for(int i = 0; i < numEmployees; i++) {
            cout << "- " << employees[i]->name << " (" << employees[i]->designation << ")\n";
        }
    }

    ~Project() {
        delete[] employees;
    }
};

int main() {
    Employee e1 = {"John", "Developer"};
    Employee e2 = {"Jane", "Designer"};

    Project p1("Web App", "2023-12-31");
    p1.addEmployee(&e1);
    p1.addEmployee(&e2);

    Project p2("Mobile App", "2024-01-15");
    p2.addEmployee(&e1);

    p1.display();
    p2.display();
    return 0;
}