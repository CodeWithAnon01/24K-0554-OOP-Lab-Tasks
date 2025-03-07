#include <iostream>
using namespace std;

class Product {
    string id;
    string name;
    int quantity;
public:
    Product(string i, string n, int q) : id(i), name(n), quantity(q) {}
    string getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
};

class Warehouse {
    Product** products;
    int maxProducts;
    int numProducts = 0;

public:
    Warehouse(int max = 100) : maxProducts(max) {
        products = new Product*[max];
    }

    void addProduct(Product* p) {
        if(numProducts < maxProducts) {
            products[numProducts++] = p;
        }
    }

    void sortProducts() {
        // Simple bubble sort
        for(int i = 0; i < numProducts-1; i++) {
            for(int j = 0; j < numProducts-i-1; j++) {
                if(products[j]->getName() > products[j+1]->getName()) {
                    Product* temp = products[j];
                    products[j] = products[j+1];
                    products[j+1] = temp;
                }
            }
        }
    }

    Product* searchById(string id) {
        for(int i = 0; i < numProducts; i++) {
            if(products[i]->getId() == id) {
                return products[i];
            }
        }
        return nullptr;
    }

    void display() {
        for(int i = 0; i < numProducts; i++) {
            cout << "ID: " << products[i]->getId() 
                 << ", Name: " << products[i]->getName() 
                 << ", Qty: " << products[i]->getQuantity() << endl;
        }
    }

    ~Warehouse() {
        for(int i = 0; i < numProducts; i++) {
            delete products[i];
        }
        delete[] products;
    }
};

int main() {
    Warehouse w;
    w.addProduct(new Product("P1", "Desk", 50));
    w.addProduct(new Product("P2", "Chair", 100));
    w.sortProducts();
    w.display();

    Product* found = w.searchById("P1");
    if(found) cout << "Found: " << found->getName() << endl;
    return 0;
}