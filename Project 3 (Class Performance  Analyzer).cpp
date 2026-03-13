#include <iostream>
using namespace std;
double highest(double arr[], int size)
{
    if (size == 0)
    {
        cout << "No data available.\n";
        return 0;
    }
    double max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
double lowest(double arr[], int size)
{
    if (size == 0)
    {
        cout << "No data available.\n";
        return 0;
    }
    double min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
double average(double arr[], int size)
{
    if (size == 0)
    {
        cout << "No data available.\n";
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double average = sum / size;
    return average;
}
void sort(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void search(double arr[], int size, double num)
{
    bool isFound = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            cout << "Found at index " << i << endl;
            isFound = true;
        }
    }
    if (isFound == false)
    {
        cout << "\nNumber not found.";
    }
}
void insert(double arr[], int &size, double num, int pos)
{
    if (pos < 1 || pos > size + 1)
    {
        cout << "\nInvalid position.";
        return;
    }
    if (size == 100)
    {
        cout << "\nArray is full.";
        return;
    }
    for (int i = size - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = num;
    size++;
}
void del(double arr[], int &size, int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "\nInvalid position.";
        return;
    }

    for (int i = pos - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;
}

void reverse(double arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        double temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
int main()
{
    int size, pos;
    double num;
    cout << "Enter number of students: ";
    cin >> size;
    if (size < 0 || size > 100)
    {
        cout << "\nInvalid size";
        return 0;
    }
    double arr[100];
    cout << "\nEnter marks of students: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nMarks: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    bool isRunning = true;
    int choice;
    while (isRunning)
    {
        cout << "\nOperations List: " << endl;
        cout << "1. Highest" << endl;
        cout << "2. Lowest" << endl;
        cout << "3. Average" << endl;
        cout << "4. Sort" << endl;
        cout << "5. Search" << endl;
        cout << "6. Insert" << endl;
        cout << "7. Delete" << endl;
        cout << "8. Reverse" << endl;
        cout << "9. Exit" << endl;
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nHighest Marks: " << highest(arr, size) << endl;
            break;
        case 2:
            cout << "\nLowest Marks: " << lowest(arr, size) << endl;
            break;
        case 3:
            cout << "\nAverage Marks: " << average(arr, size) << endl;
            break;
        case 4:
            sort(arr, size);
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            break;
        case 5:
            cout << "\nEnter number you want to search: ";
            cin >> num;
            search(arr, size, num);
            break;
        case 6:
            cout << "\nEnter number you want to insert: ";
            cin >> num;
            cout << "\nEnter position you want to insert: ";
            cin >> pos;
            insert(arr, size, num, pos);
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            break;
        case 7:
            cout << "\nEnter position you want to delete: ";
            cin >> pos;
            del(arr, size, pos);
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            break;
        case 8:
            cout << "\nReverse: ";
            reverse(arr, size);
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            break;
        case 9:
            cout << "\nExiting....";
            isRunning = false;
            break;
        default:
            cout << "\nInvalid Choice" << endl;
            break;
        }
    }
}