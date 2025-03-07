#include <iostream>
using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}
};

class Hospital {
    Doctor** doctors;
    int maxDoctors;
    int numDoctors = 0;

public:
    Hospital(int max = 10) : maxDoctors(max) {
        doctors = new Doctor*[max];
    }

    void addDoctor(Doctor* doc) {
        if(numDoctors < maxDoctors) {
            doctors[numDoctors++] = doc;
        }
    }

    void display() {
        cout << "Hospital Doctors:\n";
        for(int i = 0; i < numDoctors; i++) {
            cout << "- " << doctors[i]->name << " (" << doctors[i]->specialization << ")\n";
        }
    }

    ~Hospital() {
        delete[] doctors;
    }
};

int main() {
    Doctor d1("Alice", "Cardiology", 10);
    Doctor d2("Bob", "Neurology", 8);

    Hospital h;
    h.addDoctor(&d1);
    h.addDoctor(&d2);
    h.display();
    return 0;
}