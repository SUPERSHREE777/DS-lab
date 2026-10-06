#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Display the restaurant menu
void displayMenu() {
    cout << "\n=============================\n";
    cout << "      RESTAURANT MENU\n";
    cout << "=============================\n";
    cout << "1. Burger        - $5.99\n";
    cout << "2. Pizza         - $8.49\n";
    cout << "3. Pasta         - $7.25\n";
    cout << "4. Salad         - $4.50\n";
    cout << "5. Cold Drink    - $1.99\n";
    cout << "6. Exit\n";
    cout << "=============================\n";
    cout << "Enter your choice (1-6): ";
}

// Recursive function: shows the menu, takes a choice, and calls itself
// again until the user selects Exit. 'total' keeps the running bill.
void runMenu(double total) {
    displayMenu();

    int choice;
    if (!(cin >> choice)) {
        // Input was not a number
        if (cin.eof()) {            // input stream closed, stop recursion
            cout << "\nInput ended. Goodbye!\n";
            return;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input! Please enter a number between 1 and 6.\n";
        runMenu(total);             // recursive call
        return;
    }

    double price = 0.0;
    string item;

    switch (choice) {
        case 1: item = "Burger";     price = 5.99; break;
        case 2: item = "Pizza";      price = 8.49; break;
        case 3: item = "Pasta";      price = 7.25; break;
        case 4: item = "Salad";      price = 4.50; break;
        case 5: item = "Cold Drink"; price = 1.99; break;
        case 6:
            // Base case: stop the recursion
            cout << fixed << setprecision(2);
            cout << "\nThank you for visiting! Your total bill: $" << total << "\n";
            return;
        default:
            cout << "\nInvalid choice! Please select between 1 and 6.\n";
            runMenu(total);         // recursive call
            return;
    }

    total += price;
    cout << fixed << setprecision(2);
    cout << "\nYou selected: " << item << " ($" << price << ")\n";
    cout << "Current total: $" << total << "\n";

    runMenu(total);                 // recursive call
}

int main() {
    cout << "Welcome to our Restaurant!\n";
    runMenu(0.0);
    return 0;
}
