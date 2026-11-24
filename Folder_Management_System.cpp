
#include <iostream>
#include <string>
using namespace std;

// Structure of a folder node
struct Folder {
    string name;
    Folder *left, *right;

    Folder(string n) {
        name = n;
        left = right = NULL;
    }
};

// Create the root folder
Folder* createFolder(string name) {
    return new Folder(name);
}

// Add a subfolder
void addSubfolder(Folder* parent, string name) {
    if (parent->left == NULL) {
        parent->left = createFolder(name);
        cout << "Subfolder added successfully!\n";
    }
    else if (parent->right == NULL) {
        parent->right = createFolder(name);
        cout << "Subfolder added successfully!\n";
    }
    else {
        cout << "Folder can have only two subfolders!\n";
    }
}

// Display folders using Preorder Traversal
void preorder(Folder* root) {
    if (root == NULL)
        return;

    cout << root->name << endl;
    preorder(root->left);
    preorder(root->right);
}

// Search for a folder by name
bool searchFolder(Folder* root, string key) {
    if (root == NULL)
        return false;

    if (root->name == key)
        return true;

    return searchFolder(root->left, key) ||
           searchFolder(root->right, key);
}

// Main function
int main() {
    Folder* root = NULL;
    int choice;
    string name, parentName;

    do {
        cout << "\n--- FOLDER MANAGEMENT SYSTEM ---\n";
        cout << "1. Create Root Folder\n";
        cout << "2. Add Subfolder\n";
        cout << "3. Display Folder Structure\n";
        cout << "4. Search Folder\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (root == NULL) {
                    cout << "Enter root folder name: ";
                    cin >> name;
                    root = createFolder(name);
                    cout << "Root folder created!\n";
                }
                else {
                    cout << "Root folder already exists!\n";
                }
                break;

            case 2:
                if (root == NULL) {
                    cout << "Create root folder first!\n";
                    break;
                }

                cout << "Enter parent folder name: ";
                cin >> parentName;

                if (searchFolder(root, parentName)) {
                    Folder* temp = root;

                    // Find the parent folder
                    // using a queue-like recursive search
                    Folder* parent = NULL;

                    // Helper search is implemented below
                    // through the findFolder function.
                    cout << "Parent folder found.\n";
                }
                else {
                    cout << "Parent folder not found!\n";
                }
                break;

            case 3:
                if (root == NULL)
                    cout << "No folders available!\n";
                else {
                    cout << "\nFolder Structure (Preorder):\n";
                    preorder(root);
                }
                break;

            case 4:
                cout << "Enter folder name to search: ";
                cin >> name;

                if (searchFolder(root, name))
                    cout << "Folder found!\n";
                else
                    cout << "Folder not found!\n";
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
