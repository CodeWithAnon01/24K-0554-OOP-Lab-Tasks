#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("large_log.txt");

    char buffer[11];
    file.read(buffer, 10);  
    cout << "Position after first read: " << file.tellg() << endl;

    file.read(buffer, 10); 
    cout << "Position after second read: " << file.tellg() << endl;

    file.close();
    return 0;
}
