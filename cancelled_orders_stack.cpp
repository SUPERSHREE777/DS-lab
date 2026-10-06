#include <iostream>
#include <stack>
#include <limits>
using namespace std;

int main() {
    const int TOTAL_ORDERS = 5;
    stack<int> cancelledOrders;

    cout << "Enter " << TOTAL_ORDERS
         << " cancelled order numbers (in the order they were cancelled):\n";

    // Store the cancelled order numbers in the stack (push)
    for (int i = 1; i <= TOTAL_ORDERS; i++) {
        int orderNo;
        cout << "Cancelled order " << i << ": ";

        while (!(cin >> orderNo) || orderNo <= 0) {
            if (cin.eof()) {
                cout << "\nInput ended unexpectedly.\n";
                return 1;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid order number. Enter a positive number: ";
        }

        cancelledOrders.push(orderNo);
    }

    // Display from the most recently cancelled order (top of the stack)
    cout << "\nCancelled orders (most recent first):\n";
    cout << "-------------------------------------\n";

    int position = 1;
    while (!cancelledOrders.empty()) {
        cout << position << ". Order #" << cancelledOrders.top();
        if (position == 1) {
            cout << "  <-- most recently cancelled";
        }
        cout << "\n";
        cancelledOrders.pop();
        position++;
    }

    return 0;
}
