#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("config.txt", ios::in | ios::out);
    
    file.seekp(5, ios::beg);
    file << "XXXXX" << endl; 
    
    file.close();
    
    ifstream fileRead("config.txt");
    string line;
    while (getline(fileRead, line)) {
        cout << line << endl;
    }

    fileRead.close();
    return 0;
}
