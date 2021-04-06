// Kadanes.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the Largest Sum in Contiguous Subarray

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxSum(vector<int> val);

int main()
{
    vector<int> a = { -2, -3, 4, -1, -2, 1, 5, -3 };

    std::cout << "Max sum is " << MaxSum(a) << endl;
}

int MaxSum(vector<int> val)
{
    int max_res = val[0], cur_max = val[0];
  
    int len = val.size();

    // Go through the vector and find the maximum sum
    for (int i = 1; i < len; i++) {
        cur_max = max(val[i], cur_max + val[i]);
        max_res = max(max_res, cur_max);
 
    }
    return max_res;
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
