#include <iostream>
#include <string>
using namespace std;
int main()
{
    bool isRunning = true;
    int choice, index, size = 0, capacity = 2;
    string *names = new string[capacity];
    string *numbers = new string[capacity];
    while (isRunning)
    {
        cout << "\nContact Menu" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. View Contacts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nEnter name: ";
            cin >> names[size];
            cout << "\nEnter Phone Number: ";
            cin >> numbers[size];
            size++;

            if (size == capacity)
            {
                capacity *= 2;
                string *newNames = new string[capacity];
                string *newNumbers = new string[capacity];
                for (int i = 0; i < size; i++)
                {
                    newNames[i] = names[i];
                    newNumbers[i] = numbers[i];
                }
                delete[] names;
                delete[] numbers;
                names = newNames;
                numbers = newNumbers;
            }
            break;
        case 2:

            if (size == 0)
            {
                cout << "\nNo Contacts to Delete" << endl;
            }
            else
            {
                cout << "\nEnter contact number to delete: ";
                cin >> index;
                index--;

                if (index < 0 || index >= size)
                {
                    cout << "\nInvalid contact number" << endl;
                }
                else
                {
                    for (int i = index; i < size - 1; i++)
                    {
                        names[i] = names[i + 1];
                        numbers[i] = numbers[i + 1];
                    }
                    size--;
                }
            }
            break;
        case 3:
            if (size == 0)
            {
                cout << "\nNo Contacts" << endl;
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    cout << "\nName: " << names[i] << "\tPhone Number: " << numbers[i];
                }
            }
            break;
        case 4:
            cout << "\nExiting...";
            isRunning = false;
            break;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
    delete[] names;
    delete[] numbers;
}
