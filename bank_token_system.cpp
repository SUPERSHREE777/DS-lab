#include <iostream>
#include <queue>
#include <limits>
using namespace std;

// Issue a new token and add it to the end of the queue
void issueToken(queue<int> &tokens, int &nextToken) {
    tokens.push(nextToken);
    cout << "\nToken #" << nextToken << " issued successfully.\n";
    cout << "Customers waiting: " << tokens.size() << "\n";
    nextToken++;
}

// Display all waiting tokens from first to last
void displayTokens(const queue<int> &tokens) {
    if (tokens.empty()) {
        cout << "\nNo customers are waiting.\n";
        return;
    }

    queue<int> temp = tokens;   // copy so the original queue is not changed
    cout << "\nWaiting tokens (next to be served first):\n";
    cout << "-----------------------------------------\n";

    int position = 1;
    while (!temp.empty()) {
        cout << position << ". Token #" << temp.front();
        if (position == 1) {
            cout << "  <-- next to be served";
        }
        cout << "\n";
        temp.pop();
        position++;
    }
}

// Serve the customer at the front of the queue
void serveCustomer(queue<int> &tokens) {
    if (tokens.empty()) {
        cout << "\nNo customers to serve. The queue is empty.\n";
        return;
    }

    cout << "\nNow serving token #" << tokens.front() << "\n";
    tokens.pop();
    cout << "Customers still waiting: " << tokens.size() << "\n";
}

int main() {
    queue<int> tokens;
    int nextToken = 1;      // token numbers start from 1
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "     BANK TOKEN SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Issue a token\n";
        cout << "2. Display all tokens\n";
        cout << "3. Serve a customer\n";
        cout << "4. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                cout << "\nInput ended. Exiting.\n";
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter a number between 1 and 4.\n";
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                issueToken(tokens, nextToken);
                break;
            case 2:
                displayTokens(tokens);
                break;
            case 3:
                serveCustomer(tokens);
                break;
            case 4:
                cout << "\nThank you for using the Bank Token System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
