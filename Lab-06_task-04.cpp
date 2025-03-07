#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
public:
    Account(int an, float b) : accountNumber(an), balance(b) {}
    virtual void displayDetails() {
        cout << "Account #: " << accountNumber << "\nBalance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
    float interestRate;
public:
    SavingsAccount(int an, float b, float ir) : Account(an, b), interestRate(ir) {}
    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
    float overdraftLimit;
public:
    CheckingAccount(int an, float b, float ol) : Account(an, b), overdraftLimit(ol) {}
    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount sa(12345, 5000, 2.5);
    CheckingAccount ca(67890, 3000, 1000);
    sa.displayDetails();
    ca.displayDetails();
    return 0;
}