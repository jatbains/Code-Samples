// ReverseVowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string reverseVowels(string s);

int main()
{
    string s = "hello";

    s = reverseVowels(s);
    
    cout << s << endl;
    //std::cout << "Hello World!\n";
}

string reverseVowels(string s) {
    char vow;
    char* p, * q;

    p = q = &s[0];

    int len = s.size();
    for (int i = 0; i < len; i++)
        q++;

    //Move back one
    q--;

    while (p < q)
    {
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u')
        {
            p++;
            continue;
        }

        if (*q != 'a' && *q != 'e' && *q != 'i' && *q != 'o' && *q != 'u')
        {
            q--;
            continue;
        }

        vow = *p;
        *p = *q;
        *q = vow;
        p++;
        q--;

    }
    string reverse;
    reverse = s;
    return reverse;
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
