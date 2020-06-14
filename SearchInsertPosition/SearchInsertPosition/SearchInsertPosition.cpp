// SearchInsertPosition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
int searchInsert(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int low, int high, int target);

int main()
{
    vector<int> nums = { 1, 3, 5, 7 };
    int target = 6;

    cout << "index is " << searchInsert(nums, target);
    
    //std::cout << "Hello World!\n";
}

int searchInsert(vector<int>& nums, int target) {
    // Do a binary search
    int len = nums.size();
    // edge cases
    if (target < nums[0])
        return 0;
    if (target > nums[len - 1])
        return len;

    return binarySearch(nums, 0, len, target);
}

int binarySearch(vector<int>& nums, int low, int high, int target) {
    // Check for the base case
    if (low > high)
        return 0;   // Not found

    int mid = low + (high - low) / 2;  // mid is high + low /2
    // check the mid 
    if (target == nums[mid])
        return mid;                 // found it.

    // Check to see if between the end points of array left
    if (0 <= low && low <= mid)
        if (nums[low] < target && target < nums[low + 1])
            return low + 1;

    // right
    if (mid <= high && high <= nums.size() - 1)
        if (nums[high-1] < target && target < nums[high])
            return high;

    // Search either the left side or right side
    if (target < nums[mid])
        return binarySearch(nums, low, mid, target);
    else
        return binarySearch(nums, mid + 1, high, target);
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
