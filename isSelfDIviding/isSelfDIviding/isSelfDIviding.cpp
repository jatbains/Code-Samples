// isSelfDIviding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}
vector<int> selfDividingNumbers(int left, int right) {

    // Need to check all numbers between left and right O(n)

    // Call function to determine if number is self dividing
    vector<int> res;

    for (int i = left; i <= right; i++) {

        if (isSelfDividing(i)) {
            res.push_back(i);
        }
    }
    return res;
}

bool isSelfDividing(int num) {
    int dig = 0;

    int val = num;

    while (val > 0) {
        dig = val % 10;
        if (dig == 0)
            return false;

        if (num % dig != 0)
            return false;
        val /= 10;
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
