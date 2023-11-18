#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;

    cout << Message << " : ";
    cin >> Number;

    while(Number < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one : ";
        cin >> Number;
    }

    return Number;
}

int RevesreNumber(int Number)
{
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}

bool IsPalindromeNumber(int Number)
{
    return Number == RevesreNumber(Number);
}

int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber("Enter a Number")))
        cout << "Yes, it is a Palindrome number.\n";
    else
        cout << "No, it is NOT a Palindrome number.\n";
    return 0;
}