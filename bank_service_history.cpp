#include <iostream>
#include <stack>
#include <limits>
using namespace std;

int main() {
    const int TOTAL_SERVED = 5;
    stack<int> serviceHistory;

    cout << "Enter the token numbers of " << TOTAL_SERVED
         << " recently served customers (in the order they were served):\n";

    // Store the served token numbers in the stack (push)
    for (int i = 1; i <= TOTAL_SERVED; i++) {
        int token;
        cout << "Served customer " << i << " token: ";

        while (!(cin >> token) || token <= 0) {
            if (cin.eof()) {
                cout << "\nInput ended unexpectedly.\n";
                return 1;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid token number. Enter a positive number: ";
        }

        serviceHistory.push(token);
    }

    // Display history starting from the most recently served customer (LIFO)
    cout << "\nService History (most recent first):\n";
    cout << "------------------------------------\n";

    int position = 1;
    while (!serviceHistory.empty()) {
        cout << position << ". Token #" << serviceHistory.top();
        if (position == 1) {
            cout << "  <-- most recently served";
        }
        cout << "\n";
        serviceHistory.pop();
        position++;
    }

    return 0;
}
