#include <iostream>
using namespace std;
double add(double num1, double num2)
{
    return num1 + num2;
}
double subtract(double num1, double num2)
{
    return num1 - num2;
}
double multiply(double num1, double num2)
{
    return num1 * num2;
}
double divide(double num1, double num2)
{
    return num1 / num2;
}
double power(double num1, int exp)
{
    double result = 1;
    for (int i = 1; i <= exp; i++)
    {
        result *= num1;
    }
    return result;
}
long long factorial(int numFact)
{
    long long result = 1;
    for (int i = 1; i <= numFact; i++)
    {
        result *= i;
    }
    return result;
}
bool primeCheck(int num1)
{
    if (num1 <= 1)
    {
        return false;
    }
    for (int i = 2; i <= num1 - 1; i++)
    {
        if (num1 % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool isRunning = true;
    int choice, isPrime, exp, numFact;
    double num1, num2;

    while (isRunning)
    {
        cout << "\nFucntions" << endl;
        cout << "Which operation do you want to perform" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Power" << endl;
        cout << "6. Factorial" << endl;
        cout << "7. Prime Check" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter first number: ";
            cin >> num1;
            cout << "\nEnter second number: ";
            cin >> num2;
            cout << "\nResult: " << add(num1, num2) << endl;
            break;
        case 2:
            cout << "\nEnter first number: ";
            cin >> num1;
            cout << "\nEnter second number: ";
            cin >> num2;
            cout << "\nResult: " << subtract(num1, num2) << endl;
            break;
        case 3:
            cout << "\nEnter first number: ";
            cin >> num1;
            cout << "\nEnter second number: ";
            cin >> num2;
            cout << "\nResult: " << multiply(num1, num2) << endl;
            break;
        case 4:
            cout << "\nEnter first number: ";
            cin >> num1;
            cout << "\nEnter second number: ";
            cin >> num2;
            if (num2 == 0)
            {
                while (num2 == 0)
                {
                    cout << "\nCannot divide by Zero Enter second number again";
                    cin >> num2;
                }
            }
            cout << "\nResult: " << divide(num1, num2) << endl;
            break;
        case 5:
            cout << "\nEnter Base: ";
            cin >> num1;
            cout << "\nEnter Power: ";
            cin >> exp;
            cout << "\nResult: " << power(num1, exp) << endl;
            break;
        case 6:
            cout << "\nEnter number: ";
            cin >> numFact;
            if (num1 < 0)
            {
                cout << "\nFactorial of a negative number is not valid";
            }
            else
            {
                cout << "\nResult: " << factorial(numFact) << endl;
            }
            break;
        case 7:
            cout << "\nEnter number: ";
            cin >> num1;
            isPrime = primeCheck(num1);
            if (isPrime == true)
            {
                cout << "\nIt is Prime" << endl;
            }
            else
            {
                cout << "\nIt is not Prime";
            }
            break;
        case 8:
            cout << "\nExiting..." << endl;
            isRunning = false;
            break;
        default:
            cout << "\nInvalid Selection" << endl;
            break;
        }
    }
}