// MyAtoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

int myAtoi(string str) {

    long long ret = 0, tmp;
    int i = 0, flag = 1;
    int len = str.length();

    // special case : ""
    if (len == 0) return 0;

    // special case : "   (+/-)123"
    while (str[i] == ' ') i++;
    if (str[i] == '-') {
        i++;
        flag = -1;
    }
    else if (str[i] == '+')
        i++;

    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') break;

        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (flag == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        ret = ret * 10 + str[i] - '0';

    }

    return ret * flag;
}

int myAtoi(string str) {

    long long ret = 0, tmp;
    int i = 0, flag = 1;
    int len = str.length();

    // special case : ""
    if (len == 0) return 0;

    // special case : "   (+/-)123"
    while (str[i] == ' ') i++;
    if (str[i] == '-') {
        i++;
        flag = -1;
    }
    else if (str[i] == '+')
        i++;


    while (str[i] >= '0' && str[i] <= '9') {


        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (flag == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        ret = ret * 10 + str[i++] - '0';

    }

    return ret * flag;
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
