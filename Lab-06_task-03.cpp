#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;
public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;
public:
    Researcher(string n, int a, string r) : Person(n, a), researchArea(r) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
    int publications;
public:
    Professor(string n, int a, string s, string r, int p) 
        : Person(n, a), Teacher(n, a, s), Researcher(n, a, r), publications(p) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << "\nResearch Area: " << researchArea 
             << "\nPublications: " << publications << endl;
    }
};

int main() {
    Professor prof("Alice Smith", 45, "Computer Science", "AI", 30);
    prof.displayDetails();
    return 0;
}