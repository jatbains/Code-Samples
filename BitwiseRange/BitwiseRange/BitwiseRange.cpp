// BitwiseRange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int rangeBitwiseAnd(int m, int n);

using namespace std;

int main()
{

    int m = 5, n = 7;

    cout << rangeBitwiseAnd(m, n);
   // std::cout << "Hello World!\n";
}
int rangeBitwiseAnd(int m, int n) {

    int count = 0;
    int a = m ^ n;   // XOR is all different bits Or subtract

    while (a) {   // count all 1's that are different 
        a >>= 1;
        count++;
    }
    return (((m & n) >> count) << count);

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
