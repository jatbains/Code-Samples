// IsStringPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s);
bool isPalindromes(string s);
int firstPos(string str, int start, int end);
int lastPos(string str, int start, int end);

int main()
{
    string plans = "A man, a plan, a canal: Panama";
    string simple = "0P";
    
    cout << isPalindrome(plans);
    
}

bool isPalindrome(string s) {
    // Ignore spaces and cases

    // skip spaces check for val and val +/- 32
    int len = s.length();
    char* p = &s[0];
    char* q = p;
 
    while (*q != '\0')
        q++;

    q--;

    // Compare from outside in
    while (p < q)
    {
        while (!(*p >= 'a' && *p <= 'z') && !(*p >= 'A' && *p <= 'Z') &&
               !(*p >= '0' && *p <= '9'))
        {
            p++;
        }
        while (!(*q >= 'a' && *q <= 'z') && !(*q >= 'A' && *q <= 'Z') &&
            !(*q >= '0' && *q <= '9'))
        {
            q--;
        }

        // Check vals and caps. If all conditions are true then false
        // *p ^= 1<< 5;  
        if (*p == *q)
        {
            p++;
            q--;
            continue;
        }
        else if (*p < *q) 
        { 
            if (!((*p > 'A') && (*p + 32 == *q)))
            {
                return false;
            }
 
        } 
        else if (*q < *p)
        {
            if (!((*q > 'A') && (*q + 32 == *p)))
            {
                return false;
            }
        }
       
        p++;
        q--;
    }
    return true;
}

bool isPalindromes(string s) {
    // Ignore spaces and cases
    int firstChar = 0, lastChar = s.length() - 1;
    bool isPalin = true;

    for (int i = 0; i < s.length(); i++) {
        firstChar = firstPos(s, firstChar, lastChar);
        lastChar = lastPos(s, lastChar, firstChar);

        // break, when all letters are checked 
        if (lastChar < 0 || firstChar < 0)
            break;
        // Check for capitals too
        if (s[firstChar] == s[lastChar] || s[firstChar] + 32 == s[lastChar] ||
            s[firstChar] - 32 == s[lastChar])
        {
            firstChar++;
            lastChar--;
            continue;
        }

        // if mismatch found, break the loop 
        isPalin = false;
        break;
    }

    return (isPalin);

}
int firstPos(string str, int start, int end)
{
    int firstChar = -1;

    // Get the position of first character 
    // in the string 
    for (int i = start; i <= end; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            firstChar = i;
            break;
        }
    }

    return firstChar;
}

// Utilty function to get the position of 
// last character in the string 
int lastPos(string str, int start, int end)
{
    int lastChar = -1;

    // Get the position of last character 
    // in the string 
    for (int i = start; i >= end; i--) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            lastChar = i;
            break;
        }
    }

    return lastChar;
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
