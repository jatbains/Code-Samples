// PlusOneToString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

vector<int> plusOne(vector<int>& digits) {
    // Get length add one to end and check for carry
    // The vector may need to be resized of a new one created
    int len = digits.size();
    bool carry = false;
    int num = 0;
    // Algorithm  Reverse the vector 
    // Add one to the first number and propagate carries 
    // Resize if necessary 
    // Reverse it again / or read into a new vector
    reverseVector(digits);
    digits[0] += 1;

    for (int i = 0; i < len; i++)
    {
        num = digits[i];
        if (carry)
            num += 1;
        if (num > 9)
        {
            num %= 10;
            carry = true;
        }
        else
        {
            carry = false;
        }
        digits[i] = num;
    }
    if (carry)
    {
        digits.resize(len + 1);
        digits[len] = 1;
    }
    // Reverse again
    reverseVector(digits);
    return digits;
}

void reverseVector(vector<int>& num)
{
    int len = num.size();
    int i = 0, j = len - 1;
    int val = 0;

    while (i < j)
    {
        val = num[i];
        num[i] = num[j];
        num[j] = val;
        i++;
        j--;
    }
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
