#include <iostream>
#include <fstream>
#include <string>

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item = {101, "WidgetA"};

    
    std::ofstream outFile("inventory.dat", std::ios::binary);
    outFile.write(reinterpret_cast<char*>(&item), sizeof(item));
    outFile.close();

    
    InventoryItem loadedItem;
    std::ifstream inFile("inventory.dat", std::ios::binary);
    inFile.read(reinterpret_cast<char*>(&loadedItem), sizeof(loadedItem));
    inFile.close();

    std::cout << "Item ID: " << loadedItem.itemID << ", Item Name: " << loadedItem.itemName << std::endl;

    return 0;
}
