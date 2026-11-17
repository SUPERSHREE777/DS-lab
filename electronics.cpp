
#include <iostream>
using namespace std;

const int SIZE = 10;

struct Product {
    int id, qty;
    string name;
    float price;
    Product *next;
};

Product* table[SIZE] = {};

int hashFunction(int id) {
    return id % SIZE;
}

void add() {
    Product *p = new Product;

    cout << "Enter ID, Name, Price, Quantity: ";
    cin >> p->id >> p->name >> p->price >> p->qty;

    int i = hashFunction(p->id);
    p->next = table[i];
    table[i] = p;

    cout << "Product Added Successfully!\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        Product *p = table[i];

        while (p) {
            cout << "\nID: " << p->id
                 << "\nName: " << p->name
                 << "\nPrice: " << p->price
                 << "\nQuantity: " << p->qty << "\n";

            p = p->next;
        }
    }
}

void removeProduct() {
    int id;
    cout << "Enter Product ID to Remove: ";
    cin >> id;

    int i = hashFunction(id);
    Product *p = table[i], *prev = NULL;

    while (p && p->id != id) {
        prev = p;
        p = p->next;
    }

    if (!p) {
        cout << "Product Not Found!\n";
        return;
    }

    if (prev)
        prev->next = p->next;
    else
        table[i] = p->next;

    delete p;
    cout << "Product Removed Successfully!\n";
}

int main() {
    int ch;

    do {
        cout << "\n1. Add Product";
        cout << "\n2. Display Products";
        cout << "\n3. Remove Product";
        cout << "\n0. Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: removeProduct(); break;
            case 0: cout << "Thank You!"; break;
            default: cout << "Invalid Choice!";
        }

    } while (ch != 0);

    return 0;
}
