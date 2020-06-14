// SquaredSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

bool judgeSquareSum(int c) {
    // How to solve?  if a^2 + b^2 = n
    //  a^2 = n - b^2  also  a <= n and b <= n
    if (c == 0)
        return true;

    unordered_map<int, int> map;

    for (long a = 0; a * a <= c; ++a) {
        map[a * a] = 1;                    // we mark in map
        // Check
        if (map.find(c - a * a) != map.end())
            return true;

    }

    return false;
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
