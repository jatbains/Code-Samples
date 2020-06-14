// SingleElementInSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void SearchVals(vector<int>& nums, int l, int h, int& val);

int main()
{
    vector<int> nums = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
    int val = 0;

    SearchVals(nums, 0, nums.size() - 1, val);
    cout << "Number is " << val << endl;
}

void SearchVals(vector<int>& nums, int l, int h, int& val) {

    if (l > h)
        return;

    if (l == h) {
        val = nums[l];
        return;
    }

    int mid = l + (h - l) / 2;

    // Search odd and even
    if (mid % 2 == 0) {
        if (nums[mid] == nums[mid + 1]) {
            SearchVals(nums, mid + 2, h, val);
        }
        else {
            SearchVals(nums, l, mid, val);
        }
    }
    else {
        if (nums[mid] == nums[mid - 1]) {
            SearchVals(nums, mid + 1, h, val);
        }
        else {
            SearchVals(nums, l, mid - 1, val);
        }
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
