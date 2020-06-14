// MultiplyStringsStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
string multiplier(string num1, string num2);
string multiplyStrings(string num1, string num2);
unsigned long long int stringToInt(string s);
string reverseString(string s);

int main()
{
    // Reverse both strings  - Then multiply strings including carry 
    // Put the results into a stack - Pop off stack into a new string

   string num1 = "2", num2 = "3";

   
   cout << multiplier(num1, num2) << endl;

    
}


string multiplier(string num1, string num2) {
    // Do not convert to integers
    // Reverse both strings and multiply the digits
    // carry the carry over -  creating a new string
    // Reverse this new string
    string result;

    int len1 = num1.length();
    int len2 = num2.length();

    if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-')) {
        result += "-";
    }

    // Call multiply function
    if (num1[0] == '-')
        num1 = num1.substr(1);
    if (num2[0] == '-')
        num2 = num2.substr(1);

    result += multiplyStrings(num1, num2);

    return result;
}

string multiplyStrings(string num1, string num2) {
    vector<int> results;
    int len1 = num1.length();
    int len2 = num2.length();
    results.resize(len1 + len2 + 1);
    string mult = "";

    int i_n1 = 0, i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--) {

        int carry = 0;
        int n1 = num1[i] - '0';  // Multiple this digit

        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--) {

            int n2 = num2[j] - '0'; // multiplier digit 

            int sum = n1 * n2 + results[i_n1 + i_n2] + carry;  // Add it to previous result

            carry = sum / 10;   // Calculate carry

            // save result
            results[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            results[i_n1 + i_n2] += carry;

        i_n1++;
    }

    
    int i = results.size() - 1;
    while (i >= 0 && results[i] == 0)
        i--;

    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1)
        return "0";


    // Go through vector in reverse
 
    while (i >= 0) {
        mult += to_string(results[i--]);
    }

    return mult;
}

string multiply(string num1, string num2) {
    // Do not convert to integers
    // Reverse both strings and multiply the digits
    // carry the carry over -  creating a new string
    // Reverse this new string
    string result;
    if (num1.length() == 0 || num2.length() == 0) {

        result = "0";
        return result;
    }
    unsigned long long int value1 = 0;
    unsigned long long int value2 = 0;
    unsigned long long int mulVal = 0;

    int digit = 0;

    value1 = stringToInt(num1);
    value2 = stringToInt(num2);

    mulVal = value1 * value2;
    // int temp = mulVal;

     // Convert mulVal into string
    if (mulVal == 0) {
        result = "0";
    }
    else {

        while (mulVal > 0) {
            digit = mulVal % 10;
            mulVal /= 10;        // Divide by 10
            result.push_back(digit + '0');     // This needs to be reversed
        }

        result = reverseString(result);
    }

    return result;
}

string reverseString(string s) {
    char* p, * q;
    p = q = &s[0];
    char temp;

    for (unsigned i = 0; i < s.length(); i++)
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

    for (unsigned i = 0; i < s.length(); i++)
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
