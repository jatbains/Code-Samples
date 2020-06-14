// Atoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;
int myAtoi(string str);

int main()
{
    deque<char> number;
    string str1 = "4193 with words";
    string str = "   -42";
    bool isSpace = false;

    string num;
    for (int i = 0; i < str.length(); i++) {
        if (!isSpace && str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
            num += str[i];
        }
        if (str[i] == ' ' && !isalpha(str[i]) )
        {
            isSpace = true;
            continue;
        }
         
    }
    cout << num << endl;
    cout << myAtoi(num) << endl;
    // std::cout << "Hello World!\n";
}

int myAtoi(string str) {

    bool isNeg = false;
    int num = 0;

    for (int i = 0; i < str.length(); i++) {

        while (str[i] == ' ')
            i++;
        if (str[i] == '-') {
            isNeg = true;
            continue;
        }
        if (isalpha(str[i])) {
            num = 0;
            break;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + str[i] - '0';
        }

    }
    
    if (isNeg)
        num *= -1;

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
