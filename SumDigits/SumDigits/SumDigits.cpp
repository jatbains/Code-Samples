// SumDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int addDigits(int num);

using namespace std;


int main()
{
    int num = 19;


    cout << addDigits(num) << endl;


    //std::cout << "Hello World!\n";
}


int addDigits(int num) {
    int sum = 0;
    int dig = 0;
    do {
        sum = 0;
        do {
            dig = num % 10;
            num /= 10;
            sum += dig;
        } while (num > 0);

        num = sum;

    } while (!(sum < 10));

    return sum;
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
