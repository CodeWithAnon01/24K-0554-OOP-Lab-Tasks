#include <iostream>
#include <string>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string dishName, double price) : dishName(dishName), price(price) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string dishName, double price) : MenuItem(dishName, price) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << ", Price: " << price << endl;
    }

    void prepare() override {
        cout << "Preparing appetizer: " << dishName << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string dishName, double price) : MenuItem(dishName, price) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << ", Price: " << price << endl;
    }

    void prepare() override {
        cout << "Preparing main course: " << dishName << endl;
    }
};

int main() {
    MenuItem* dish1 = new Appetizer("Spring Rolls", 5.99);
    MenuItem* dish2 = new MainCourse("Grilled Chicken", 12.99);

    dish1->showDetails();
    dish1->prepare();

    cout << endl;

    dish2->showDetails();
    dish2->prepare();

    delete dish1;
    delete dish2;

    return 0;

}



// Outputs
// Appetizer: Spring Rolls, Price: 5.99
// Preparing appetizer: Spring Rolls

// Main Course: Grilled Chicken, Price: 12.99
// Preparing main course: Grilled Chicken
