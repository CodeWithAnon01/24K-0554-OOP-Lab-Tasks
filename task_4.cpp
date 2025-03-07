#include <iostream>
using namespace std;

class AlarmSystem {
    string securityLevel;
public:
    AlarmSystem(string level) : securityLevel(level) {}
    void display() { cout << "Security Level: " << securityLevel << endl; }
};

class SmartHome {
    AlarmSystem alarm;
public:
    SmartHome(string level) : alarm(level) {}
    void display() { 
        cout << "Smart Home Details:\n"; 
        alarm.display(); 
    }
};

int main() {
    SmartHome home("High");
    home.display();
    return 0;
}