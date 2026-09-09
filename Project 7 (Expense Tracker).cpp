#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Expense
{
    double amount;
    string category;
    string month;
};

int main()
{
    bool isRunning = true;
    int choice;
    Expense expenses[100];
    int expenseCount = 0;
    while (isRunning)
    {
        cout << "\nExpense Tracker" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View All Expenses" << endl;
        cout << "3. Monthly Summary" << endl;
        cout << "4. Save and exit" << endl;
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (expenseCount >= 100)
            {
                cout << "Expense list is fill!" << endl;
                break;
            }
            cout << "Enter the Amount , Category and Month: ";
            cin >> expenses[expenseCount].amount;
            cin.ignore();
            getline(cin, expenses[expenseCount].category);
            getline(cin, expenses[expenseCount].month);
            expenseCount++;
            cout << "Expense recorded successfully!" << endl;
            break;
        }
        case 2:
        {
            if (expenseCount == 0)
            {
                cout << "No expenses recorded yet." << endl;
            }
            for (int i = 0; i < expenseCount; i++)
            {
                cout << i + 1 << ". " << "Category : " << expenses[i].category
                     << "\n  Amount : " << expenses[i].amount
                     << "\n  Month : " << expenses[i].month << endl;
            }
            break;
        }
        case 3:
        {
            string month;
            double total = 0;
            int count = 0;
            cout << "Enter the month for the Summary: ";
            cin.ignore();
            getline(cin, month);
            for (int i = 0; i < expenseCount; i++)
            {
                if (expenses[i].month == month)
                {
                    total += expenses[i].amount;
                    count++;
                }
            }
            cout << "Number of Expenses : " << count
                 << "\nTotal " << total << endl;
            break;
        }
        case 4:
            cout << "\nExiting...." << endl;
            isRunning = false;
            break;
        default:
            cout << "\nInvalid Output" << endl;
            break;
        }
    }
}