#include <iostream>
using namespace std;
void checkPassword(char password[])
{
    int length = 0;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUpper = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLower = true;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasDigit = true;
        }
        else
        {
            hasSpecial = true;
        }
        length++;
    }
    if (length < 6)
    {
        cout << "Weak Password\n";
        return;
    }
    else if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
    {
        cout << "Strong Password\n";
        return;
    }
    else
    {
        cout << "Medium Strength\n";
        return;
    }
}
int countWords(char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {

        if (text[i] != ' ' && (i == 0 || text[i - 1] == ' '))
        {
            count++;
        }
    }
    return count;
}
int countSentences(char text[])
{
    int sentenceCount = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}
char findMostFrequent(char text[])
{
    int freq[256] = {0};
    int max = 0;
    int index = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ')
        {
            freq[text[i]]++;
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            index = i;
        }
    }
    return (char)index;
}
void reverseText(char text[])
{
    int length = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        length++;
    }
    int start = 0, end = length - 1;
    while (start < end)
    {
        int temp = text[start];
        text[start] = text[end];
        text[end] = temp;
        start++;
        end--;
    }
}
void removeDuplicates(char text[])
{
    int length = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            char ch1 = text[i];
            char ch2 = text[j];
            if (ch1 >= 'A' && ch1 <= 'Z')
            {
                ch1 += 32;
            }
            if (ch2 >= 'A' && ch2 <= 'Z')
            {
                ch2 += 32;
            }
            if (ch1 == ch2)
            {
                for (int k = j; k < length - 1; k++)
                {
                    text[k] = text[k + 1];
                }
                length--;
                j--;
                text[length] = '\0';
            }
        }
    }
}
int main()
{
    bool isRunning = true;
    int choice;
    char password[100];
    char text[500];
    while (isRunning)
    {
        cout << "\nMenu";
        cout << "\n1. Password Checker";
        cout << "\n2. Text Analyzer";
        cout << "\n3. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Password: ";
            cin >> password;
            checkPassword(password);
            break;

        case 2:
        {
            cout << "\nEnter Text: " << endl;
            cin.ignore();
            cin.getline(text, 500);
            cout << "Total Words: " << countWords(text) << endl;
            cout << "Total Sentences: " << countSentences(text) << endl;
            char most = findMostFrequent(text);
            cout << "Most Frequent Character: " << most << endl;
            removeDuplicates(text);
            cout << "Duplicate Characters Removed: " << text << endl;
            reverseText(text);
            cout << "Reverse Text: " << text << endl;
            break;
        }
        case 3:
            cout << "\nExiting...." << endl;
            isRunning = false;
            break;

        default:
            cout << "\nInvalid Choice" << endl;
            break;
        }
    }
}