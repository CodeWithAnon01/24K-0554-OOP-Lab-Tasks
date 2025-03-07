#include <iostream>
#include <cstring>
using namespace std;

class Apartment {
    int id;
    string address;
    char* ownerName;
public:
    Apartment(int id, string addr, const char* owner) : id(id), address(addr) {
        ownerName = new char[strlen(owner) + 1];
        strcpy(ownerName, owner);
    }

    // Shallow copy constructor
    Apartment(const Apartment& other) : id(other.id), address(other.address), ownerName(other.ownerName) {}

    void display() {
        cout << "ID: " << id << "\nAddress: " << address << "\nOwner: " << ownerName << endl;
    }

    ~Apartment() {
        delete[] ownerName;
    }
};

int main() {
    Apartment a1(101, "123 Main St", "John Doe");
    Apartment a2 = a1;

    cout << "Original Apartment:\n";
    a1.display();
    cout << "\nCopied Apartment:\n";
    a2.display();
    return 0;
}