#include <iostream>
using namespace std;
int main()
{
    int pin = 4321, pinCheck;
    bool pinAuthenticated = false;
    cout << "Enter PIN CODE: ";
    for (int i = 1; i <= 3; i++)
    {
        cin >> pinCheck;
        if (pin == pinCheck)
        {
            cout << "PIN Authentication Successful" << endl;
            pinAuthenticated = true;
            break;
        }
        else if (i < 3)
        {
            cout << "Wrong PIN Try again: ";
        }
    }
    if (pinAuthenticated == false)
    {
        cout << "\nAuthentication Failed Your Account is blocked";
        return 0;
    }
    bool isRunning = true;
    int choice;
    double balance = 0.0, depositAmount, withdrawAmount;

    while (isRunning)
    {
        cout << "\nMenu Options" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Check Balance selected" << endl;
            cout << "Balance: " << balance << endl;
            break;
        case 2:
            cout << "Deposit selected" << endl;
            cout << "Enter amount you want to deposit: " << endl;

            cin >> depositAmount;
            if (depositAmount > 0)
            {
                cout << "Deposit Successful" << endl;
                balance += depositAmount;
                break;
            }
            else
            {
                cout << "Negative Amount Deposit Failed" << endl;
                break;
            }
        case 3:
            cout << "Withdraw selected" << endl;
            cout << "Enter amount you want to Withdraw: ";
            cin >> withdrawAmount;
            if (withdrawAmount > 0 && withdrawAmount <= balance)
            {
                cout << "Withdraw Successful" << endl;
                balance -= withdrawAmount;
                break;
            }
            else if (withdrawAmount < 0)
            {
                cout << "Negative Amount Withdraw Failed" << endl;
                break;
            }
            else
            {
                cout << "Withdraw Amount greater than Balance Withdraw Failed" << endl;
                break;
            }

            break;
        case 4:
            cout << "Change PIN selected" << endl;
            cout << "Enter new PIN: ";
            cin >> pin;
            cout << "Authentication PIN updated successfully" << endl;
            break;
        case 5:
            cout << "Exiting" << endl;
            isRunning = false;
            break;
        default:
            cout << "Invalid Option";
            break;
        }
    }
}