// GetNonZeros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}
vector<int> getNoZeroIntegers(int n) {

    // Start at 1 and check i and n-i
    vector<int> res;

    for (int i = 1; i <= n / 2; i++) {
        if (anyZeros(i) && anyZeros(n - i)) {
            res.push_back(i);
            res.push_back(n - i);
            break;
        }
    }
    return res;
}

bool anyZeros(int n) {

    while (n > 0) {
        if (n % 10 == 0)
            return false;
        n /= 10;
    }
    return true;
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
