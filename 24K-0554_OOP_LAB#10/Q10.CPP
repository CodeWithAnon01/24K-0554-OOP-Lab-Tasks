#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data_records.txt");

    file.seekg(17, ios::beg); 
    
    string record;
    getline(file, record);
    cout << "Third Record: " << record << endl;

    file.close();
    return 0;
}
