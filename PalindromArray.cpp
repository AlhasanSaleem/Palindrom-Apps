#include <iostream>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;

    cout << Message << " : ";
    cin >> Number;

    while (Number < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one : ";
        cin >> Number;
    }
    return Number;
}

void FillArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Enter element number [" << i + 1 << "] : ";
        cin >> *(ptr + i);

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one : ";
            cin >> *(ptr + i);
        }
        
    }
}

bool IsPalindromArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (*(ptr + i) != *(ptr + (arrLength - i - 1)))
            return false;

    }
    return true;
}

void PrintArray(int* ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i ++)
        cout << *(ptr + i) << " ";
}

int main()
{
    int arrLength = 0, *ptr;
    arrLength = ReadPositiveNumber("How many number of array elements ?");
    ptr = new int[arrLength];
    FillArray(ptr, arrLength);
    PrintArray(ptr, arrLength);
    if (IsPalindromArray(ptr, arrLength))
        cout << "\nYes array is Palindrome\n";
    else       
        cout << "\nNO array is NOT Palindrome\n";
    return 0;
    delete[] ptr;  // ptr memory is released
}