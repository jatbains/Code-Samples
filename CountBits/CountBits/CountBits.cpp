// CountBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num);

int main()
{
    int num = 5;
    vector<int> bits = countBits(num);
    for (int i : bits)
        cout << i;
}

vector<int> countBits(int num) {

    vector<int> bits;
    unsigned int mask = 1;   // 
    
    while (mask <= num) {
        if (num & mask)
            bits.insert(bits.begin(),1);
        else
            bits.insert(bits.begin(),0);

        mask <<= 1;
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
