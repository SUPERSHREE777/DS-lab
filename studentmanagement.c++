```cpp
#include <iostream>
using namespace std;

int main()
{
    int rollNo[10];
    int marks[10];
    int n = 0;
    int choice;
    int searchRoll;

    do
    {
        cout << "\n--- STUDENT MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter Roll No: ";
            cin >> rollNo[n];

            cout << "Enter Marks: ";
            cin >> marks[n];

            n++;

            cout << "Student added successfully!\n";
        }

        else if(choice == 2)
        {
            cout << "\nStudent Records:\n";

            for(int i = 0; i < n; i++)
            {
                cout << "Roll No: " << rollNo[i];
                cout << "  Marks: " << marks[i] << endl;
            }
        }

        else if(choice == 3)
        {
            cout << "Enter Roll No to search: ";
            cin >> searchRoll;

            bool found = false;

            for(int i = 0; i < n; i++)
            {
                if(rollNo[i] == searchRoll)
                {
                    cout << "Student Found!\n";
                    cout << "Roll No: " << rollNo[i] << endl;
                    cout << "Marks: " << marks[i] << endl;

                    found = true;
                }
            }

            if(found == false)
            {
                cout << "Student not found!\n";
            }
        }

        else if(choice == 4)
        {
            cout << "Exiting program...\n";
        }

        else
        {
            cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
```
