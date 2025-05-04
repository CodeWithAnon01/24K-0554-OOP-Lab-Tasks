#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("sensor_log.txt");

    file << "Sensor 1: 25.5 C" << endl;
    cout << "Position after first write: " << file.tellp() << endl;

    file << "Sensor 2: 98.1 %RH" << endl;
    cout << "Position after second write: " << file.tellp() << endl;

    file.close();
    return 0;
}
