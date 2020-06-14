// AddStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;
string addStrings(string num1, string num2);
int GetNumString(string s);
string AddStringsLinearly(string num1, string num2);
string findSum(string str1, string str2);

int main()
{
    string num1 = "1231";
    string num2 = "567";
    
    cout << AddStringsLinearly(num1, num2) << endl;
    cout << findSum(num1, num1) << endl;
    cout << addStrings(num1, num2) << endl;
    
    //std::cout << "Hello World!\n";
}

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result 
    string str = "";

    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        // Calculate carry for next step 
        carry = sum / 10;
    }

    // Add remaining digits of larger number 
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry 
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string 
    reverse(str.begin(), str.end());

    return str;
}

#if 0
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result 
    string str = "";

    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero 
    int carry = 0;

    // Traverse from end of both strings 
    for (int i = n1 - 1; i >= 0; i--)
    {
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i] - '0') +
            (str2[i + diff] - '0') +
            carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining digits of str2[] 
    for (int i = n2 - n1 - 1; i >= 0; i--)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry 
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string 
    reverse(str.begin(), str.end());

    return str;
}
#endif

string AddStringsLinearly(string num1, string num2)
{
    string sum;
    int l1 = num1.length();
    int l2 = num2.length();
    int diff, ls;
    int range = 0;
    int carry = 0;
    int digit = 0;

    // Depending on which string is longer process those
    if (l1 >= l2)
    {
        sum.resize(l1 + 1);
        ls = l1 + 1;
        while (l1 > 0) {
            if (l2 > 0) {
                if (carry) {
                    digit = 1 + (num1[l1-1] - '0') + (num2[l2-1] = '0');
                    if (digit > 9) {
                        digit %= 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sum[ls-1] = digit + '0';
                }
                else {
                    digit = (num1[l1-1] - '0') + (num2[l2-1] - '0');
                    if (digit > 9) {
                        digit %= 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sum[ls-1] = digit + '0';
                }
                l2--;
                l1--;
            }
            else {
                if (carry) {
                    digit = num1[l1 - 1] + 1;
                    if (digit > 9) {
                        digit %= 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sum[ls-1] = digit + '0';
                }
                else
                {
                    sum[ls-1] = num1[l1];
                }

                l1--;
            }

            ls--;
        
        }
    }
    else
    {
        sum.resize(l2 + 1);
        ls = l2 + 1;
        while (l2 > 0) {
            if (l1 > 0) {
                if (carry) {
                    digit = 1 + (num1[l1] - '0') + (num2[l2] - '0');
                    if (digit > 9) {
                        digit %= 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sum[ls - 1] = digit + '0';
                }
                else
                {
                    digit = (num1[l1] - '0') + (num2[l2] - '0');
                    if (digit > 9) {
                        digit %= 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sum[ls - 1] = digit + '0';
                }
                l2--;
                l1--;
            }
            else {
                if (carry) {
                    digit = num2[l2 - 1] + 1;
                    if (digit > 9) {
                        digit %= 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sum[ls-1] = digit + '0';
                }
                else
                {
                    sum[ls-1] = num2[l2];
                }
                
                l2--;
            }

            ls--;
        }
    }
    return sum;
}

string addStrings(string num1, string num2) {
    string sum;
    stack<int> sumstack;
    int intsum = 0;
    int l1 = num1.size();
    int l2 = num2.size();
    int val1 = 0;
    int val2 = 0;
    int dig = 0;

    if (l1 == 0 && l2 == 0)
    {
        return sum;
    }

    // Get numbers
    val1 = GetNumString(num1);
    val2 = GetNumString(num2);

    intsum = val1 + val2;
    int len = 1;
    // Convert this to a string
    while (intsum > 0)
    {
        dig = intsum % 10;
        sumstack.push(dig);
        intsum /= 10;
        len++;
    }
    // Pop off stack into string
    int i = 0;
    sum.resize(len);
    while (!sumstack.empty())
    {
        dig = sumstack.top();
        sum[i] = dig + '0';
        sumstack.pop();
        i++;
    }

    return sum;
}
int GetNumString(string s)
{
    int num = 0;
    int len = s.size();
    int dig = 0;
    for (int i = 0; i < len; i++)
    {
        dig = s[i] - '0';
        num = num * 10 + dig;
    }
    return num;
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
