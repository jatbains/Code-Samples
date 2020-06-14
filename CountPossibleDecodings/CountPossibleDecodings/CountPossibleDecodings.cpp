// CountPossibleDecodings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int CountingDP(string s);

int main()
{
    string  digits = "1234";

    cout << CountingDP(digits) << endl;

    //std::cout << "Hello World!\n";
}

int CountingDP(string s) {
    int n = s.length();
    int a = 1;
    int b = 1;
    int c = 0;
    int* count = new int[n+1];
    count[0] = 1;
    count[1] = 1;

    // Count up to n
    if (s[0] == '0')
        return 0;

    for (int i = 2; i <= n; i++) {

        count[i] = 0;
        if (s[i-1] > '9') {
            c = b;
            count[i] = count[i - 1];
        }

        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
            c += a;
            count[i] += count[i - 2];
        }
        a = b;
        b = c;

    }
    return c;
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
