// MultiplyStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string multiplyStrings(string num1, string num2);
unsigned long long int stringToInt(string s);
string reverseString(string s);

int main()
{
    string num1 = "498828660196";
    string num2 = "840477629533";
    

      
    cout << stringToInt(num1) << endl;
    cout << stringToInt(num2) << endl;

    cout << multiplyStrings(num1, num2) << endl;
  
}

string multiplyStrings(string num1, string num2) {
    // Do not convert to integers
    // Reverse both strings and multiply the digits
    // carry the carry over -  creating a new string
    // Reverse this new string

    unsigned long long int value1 = 0;
    unsigned long long int value2 = 0;
    unsigned long long int mulVal = 0;
    string result;
    int digit = 0;

    value1 = stringToInt(num1);
    value2 = stringToInt(num2);

    mulVal = value1 * value2;
   // int temp = mulVal;
    
    // Convert mulVal into string

    while (mulVal > 0) {
        digit = mulVal % 10;
        mulVal /= 10;        // Divide by 10
        result.push_back(digit + '0');     // This needs to be reversed
    }

    result = reverseString(result);

    return result;
}

string reverseString(string s) {
    char* p, * q;
    p = q = &s[0];
    char temp;

    for (int i = 0; i < s.length(); i++)
        q++;

    q--;
    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }

    return s;
}

unsigned long long int stringToInt(string s)
{

    int len = s.length();
    unsigned long long int value = 0;
    char c;

    for (int i = 0; i < s.length(); i++)
    {
        c = s[i];
        value = value * 10 + (c - '0');
    }
    return value;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
