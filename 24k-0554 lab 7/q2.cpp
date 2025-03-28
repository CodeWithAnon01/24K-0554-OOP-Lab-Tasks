#include <iostream>
#include <cstring>

using namespace std;

class Product {
protected:
    int productID;
    char productName[50];
    float price;
    int stockQuantity;

public:
    Product(int id, const char* name, float cost, int stock = 0) {
        productID = id;
        strcpy(productName, name);
        price = cost;
        stockQuantity = stock;
    }

    virtual float applyDiscount() {
        return price; // No discount (default
    }

    virtual float calculateTotalPrice(int quantity) {
        return applyDiscount() * quantity;
    }

    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << ", Name: " << productName 
             << ", Price: $" << price << ", Stock: " << stockQuantity << "\n";
    }

    // Overloading operator
    float operator+(const Product& other) {
        return this->price + other.price;
    }

    // Overloading operator<< for formatted output
    friend ostream& operator<<(ostream& out, const Product& p) {
        out << "Product ID: " << p.productID << "\n"
            << "Name: " << p.productName << "\n"
            << "Price: $" << p.price << "\n"
            << "Stock: " << p.stockQuantity << "\n";
        return out;
    }
};

// Derived Classes

class Electronics : public Product {
private:
    int warrantyPeriod;
    char brand[30];

public:
    Electronics(int id, const char* name, float cost, int stock, int warranty, const char* brandName) 
        : Product(id, name, cost, stock), warrantyPeriod(warranty) {
        strcpy(brand, brandName);
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << ", Warranty: " << warrantyPeriod << " years\n";
    }
};

class Clothing : public Product {
private:
    char size[10];
    char color[20];

public:
    Clothing(int id, const char* name, float cost, int stock, const char* sz, const char* clr) 
        : Product(id, name, cost, stock) {
        strcpy(size, sz);
        strcpy(color, clr);
    }

    float applyDiscount() override {
        return price * 0.90; // 10% discount on clothing
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Size: " << size << ", Color: " << color << "\n";
    }
};

class FoodItem : public Product {
private:
    char expirationDate[20];
    int calories;

public:
    FoodItem(int id, const char* name, float cost, int stock, const char* expiry, int cal) 
        : Product(id, name, cost, stock), calories(cal) {
        strcpy(expirationDate, expiry);
    }

    float calculateTotalPrice(int quantity) override {
        if (quantity >= 10) return price * quantity * 0.85; // 15% bulk discount
        return price * quantity;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Expires on: " << expirationDate << ", Calories: " << calories << " kcal\n";
    }
};

// Book
class Book : public Product {
private:
    char author[50];
    char genre[30];

public:
    Book(int id, const char* name, float cost, int stock, const char* auth, const char* gen) 
        : Product(id, name, cost, stock) {
        strcpy(author, auth);
        strcpy(genre, gen);
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << ", Genre: " << genre << "\n";
    }
};

// Main
int main() {
    Electronics laptop(101, "Laptop", 999.99, 5, 2, "Dell");
    Clothing tshirt(201, "T-Shirt", 19.99, 50, "M", "Blue");
    FoodItem apple(301, "Apple", 1.99, 100, "2025-04-10", 95);
    Book novel(401, "The Alchemist", 12.99, 30, "Paulo Coelho", "Fiction");

    cout << "Product Details:\n";
    cout << laptop << "\n" << tshirt << "\n" << apple << "\n" << novel << "\n";

    cout << "Discounted Price for T-Shirt: $" << tshirt.applyDiscount() << "\n";
    cout << "Total Price for 12 Apples: $" << apple.calculateTotalPrice(12) << "\n";


    cout << "Total cost of Laptop and Book: $" << (laptop + novel) << "\n";

    return 0;
}
