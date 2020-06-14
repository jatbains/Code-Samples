// StringCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int compressPointer(vector<char>& chars);

int main()
{
    vector<char> list = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };

    cout << compressPointer(list) << endl;
    for (char c : list) {
        cout << c;
    }
}

int compressPointer(vector<char>& chars) {
    int freq = 0;
    char c;
    char* slow, * fast, * begin;
    int len = chars.size();
    slow = fast = &chars[0];
    begin = slow;
    int sub = 0;
    int count = 0;

    
    while (count < len)
    {
        c = *slow;
        while (*slow == *fast)
        {
            freq++;
            fast++;
        }
        // Move forward
        *begin = c;
        begin++;
        *begin = freq + '0';
        sub += 2;
        begin++;

        count += freq;
        count++;
        // Move the pointers 
        fast++;
        slow = fast;
        freq = 0;
    }
    *begin = '\0';

    return sub;
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
