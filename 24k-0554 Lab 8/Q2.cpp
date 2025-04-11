#include <iostream>
using namespace std;

class Account;

class Manager {
public:
    static void deposit(Account& acc, double amount);
    static void withdraw(Account& acc, double amount);
    static void display(const Account& acc);
};

class Account {
private:
    string accNumber;
    double balance;

public:
    Account(string num, double bal) : accNumber(num), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

void Manager::deposit(Account& acc, double amount) {
    acc.balance += amount;
}

void Manager::withdraw(Account& acc, double amount) {
    if (acc.balance >= amount) acc.balance -= amount;
}

void Manager::display(const Account& acc) {
    cout << "Account: " << acc.accNumber << ", Balance: $" << acc.balance << endl;
}

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    }
}

int main() {
    Account a("A123", 1000), b("B456", 500);
    Manager::display(a); // Before
    Manager::deposit(a, 200);
    Manager::withdraw(b, 100);
    transferFunds(a, b, 300);
    Manager::display(a); // After
    Manager::display(b);
    return 0;
}