// ReverseKCharsinString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
string reverseStr(string s, int k);
void reversekchars(string& s, int index, int k);


int main()
{
    string s = "abcdefg";
    int k = 2;

    // Call reverse method
    cout << reverseStr(s, k);
   
}

string reverseStr(string s, int k) {
    int len = s.length();
    int count = 0;
    int index = 0;
    bool skip = false;
    // Sanitize
    if (len == 0 || len == 1)
        return s;
    // Reverse k chars for every 2k

    // Move pointer forward to new index
    while (count < len)
    {
        if (count % k == 0 && skip == false)
        {
            // Reverse k
            reversekchars(s, index, k);
            index += k;  // move index forward 
            // skip next k
            skip = ~skip;  // flip skip true to false and false to true
        }
        // Move index
        count++;

    }
}

void reversekchars(string& s, int index, int k)
{
    // between index and index + k reverse chars
    char temp;
    int i = index, j = index + k;
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        // Move indices
        i++;
        j--;
    }
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
