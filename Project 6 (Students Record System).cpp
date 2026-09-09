#include <iostream>
#include <string>
using namespace std;
struct Student
{
    int rollNo;
    string name;
    double marks;
};
int main()
{
    bool isRunning = true;
    int choice;
    Student students[100] = {0};
    int studentCount = 0;

    while (isRunning)
    {
        cout << "\nStudent Record System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Update Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Calculate GPA" << endl;
        cout << "6. Sort by marks" << endl;
        cout << "7. Save and exit" << endl;
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (studentCount >= 100)
            {
                cout << "Student list is full!" << endl;
                break;
            }
            cout << "Enter Name , Roll No and marks of Student " << studentCount + 1 << " : ";
            cin.ignore();
            getline(cin, students[studentCount].name);
            cin >> students[studentCount].rollNo >> students[studentCount].marks;
            studentCount++;
            cout << "Student Added Successfully!" << endl;
            break;
        }
        case 2:
        {
            int searchRoll = 0;
            cout << "Enter student Roll No you want to search: ";
            cin >> searchRoll;
            bool isFound = false;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].rollNo == searchRoll)
                {
                    cout << "Name : " << students[i].name
                         << " , Roll No : " << students[i].rollNo
                         << " , Marks : " << students[i].marks << endl;
                    isFound = true;
                    break;
                }
            }
            if (isFound == false)
            {
                cout << "Student not found!" << endl;
            }

            break;
        }
        case 3:
        {
            int searchRoll = 0;
            cout << "Enter student Roll No you want to Update: ";
            cin >> searchRoll;
            bool isFound = false;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].rollNo == searchRoll)
                {
                    isFound = true;
                    cout << "Enter the updated Name and Marks of Roll No : " << students[i].rollNo << " : ";
                    cin.ignore();
                    getline(cin, students[i].name);
                    cin >> students[i].marks;
                    cout << "Student Record Updated successfully!" << endl;
                    break;
                }
            }
            if (isFound == false)
            {
                cout << "Student not found!" << endl;
            }

            break;
        }
        case 4:
        {
            int searchRoll = 0;
            cout << "Enter student Roll No you want Delete: ";
            cin >> searchRoll;
            bool isFound = false;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].rollNo == searchRoll)
                {
                    for (int j = i; j < studentCount - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }
                    studentCount--;
                    isFound = true;
                    break;
                }
            }
            if (isFound == false)
            {
                cout << "Student not found!" << endl;
            }

            break;
        }

        case 5:
        {
            int searchRoll = 0;
            cout << "Enter student Roll No you want the GPA of: ";
            cin >> searchRoll;
            bool isFound = false;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].rollNo == searchRoll)
                {
                    isFound = true;
                    double GPA = (students[i].marks / 100) * 4.0;
                    cout << students[i].name << " -> " << "GPA : " << GPA << endl;
                    break;
                }
            }
            if (isFound == false)
            {
                cout << "Student not found!" << endl;
            }

            break;
        }
        case 6:
        {
            for (int i = 0; i < studentCount - 1; i++)
            {
                for (int j = 0; j < studentCount - 1 - i; j++)
                {
                    if (students[j].marks > students[j + 1].marks)
                    {
                        Student temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            cout << "Records sorted successfully! " << endl;
            break;
        }

        case 7:
            cout << "\nExiting...." << endl;
            isRunning = false;
            break;
        default:
            cout << "\nInvalid Output" << endl;
            break;
        }
    }
}