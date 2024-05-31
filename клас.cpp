#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class ShopItemOrder {
private:
    string itemName;
    double itemUnitPrice;
    int numberOfItems;

public:
    
    ShopItemOrder(string name, double price, int quantity)
        : itemName(name), itemUnitPrice(price), numberOfItems(quantity) {}

    
    string getItemName() const {
        return itemName;
    }

    void setItemName(const string& name) {
        itemName = name;
    }

    
    double getItemUnitPrice() const {
        return itemUnitPrice;
    }

    void setItemUnitPrice(double price) {
        if (price >= 0) {
            itemUnitPrice = price;
        }
    }

    
    int getNumberOfItems() const {
        return numberOfItems;
    }

    void setNumberOfItems(int quantity) {
        if (quantity >= 0) {
            numberOfItems = quantity;
        }
    }

    
    double getTotalPrice() const {
        return itemUnitPrice * numberOfItems;
    }

    
    void printOrder() const {
        cout << "Назва товару: " << itemName << endl;
        cout << "Ціна за одиницю: " << itemUnitPrice << " грн" << endl;
        cout << "Кількість замовлених одиниць: " << numberOfItems << endl;
        cout << "Загальна вартість замовлення: " << getTotalPrice() << " грн" << endl;
    }
};

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    
    ShopItemOrder order("Яблуко", 5.50, 10);

    
    order.printOrder();

    
    order.setItemName("Банан");
    order.setItemUnitPrice(3.75);
    order.setNumberOfItems(20);

    
    order.printOrder();

    return 0;
}