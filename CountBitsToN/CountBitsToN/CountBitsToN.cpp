// CountBitsToN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

vector<int> countBits(int num) {


    // For all numbers output a vector     
    vector<int> bits(num + 1);
    // Appears to by a Dynamic Programming problem
    // OPtimal substructure and overlapping solutions  repeating pattern
    // if num is 0 , 0 bits , if num is 1 , 1 bit, 2 is 1, 3, 2, 4 is 1, 5 is 2, 6 is 2
    bits[0] = 0;
    if (num == 0)
        return bits;
    bits[1] = 1;
    if (num == 1)
        return bits;

    //if (i%2==1) dp[i] = dp[i - 1] + 1 if (i ) % 2 == 0  dp[i] == dp[i/2]
    for (int i = 2; i <= num; i++) {
        if (i % 2 == 1) {
            bits[i] = bits[i - 1] + 1;
        }
        else {
            bits[i] = bits[i / 2];
        }

    }

    return bits;
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
