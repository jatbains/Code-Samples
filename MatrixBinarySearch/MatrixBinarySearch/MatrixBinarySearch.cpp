// MatrixBinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
void BinaryCount(vector<int>& vals, int& count, int l, int h);

int main()
{
    std::cout << "Hello World!\n";
}

void BinaryCount(vector<int>& vals, int& count,int l, int h) {

    if (l > h)
        return;

    int mid = l + (h - l) / 2;

    if (vals[mid] < 0)
        count++;

    // Search
    if (vals[mid] < 0) {
        // Search whole row
        BinaryCount(vals, count, l, mid - 1);
    }
    else {
        BinaryCount(vals, count, mid + 1, h);
    }

}

void MatrixCount(vector<vector<int>>& nums, int& negs) {
    
    int R = nums.size();    // Rows
    int M = nums[0].size();   // columns

    for (int i = 0; i < nums.size(); i++) {

        BinaryCount(nums[i], negs, 0, nums[i].size() - 1);

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
