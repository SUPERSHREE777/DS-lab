#include <iostream>
#include <queue>
#include <limits>
using namespace std;

int main() {
    const int TOTAL_CUSTOMERS = 5;
    queue<int> tokenQueue;

    cout << "Enter " << TOTAL_CUSTOMERS
         << " customer token numbers (in the order they were issued):\n";

    // Store the token numbers in the queue (enqueue)
    for (int i = 1; i <= TOTAL_CUSTOMERS; i++) {
        int token;
        cout << "Token " << i << ": ";

        while (!(cin >> token) || token <= 0) {
            if (cin.eof()) {
                cout << "\nInput ended unexpectedly.\n";
                return 1;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid token number. Enter a positive number: ";
        }

        tokenQueue.push(token);
    }

    // Serve customers in the same order they received their tokens (FIFO)
    cout << "\nServing customers (first come, first served):\n";
    cout << "---------------------------------------------\n";

    int count = 1;
    while (!tokenQueue.empty()) {
        cout << count << ". Now serving token #" << tokenQueue.front() << "\n";
        tokenQueue.pop();
        count++;
    }

    cout << "\nAll customers have been served.\n";
    return 0;
}
