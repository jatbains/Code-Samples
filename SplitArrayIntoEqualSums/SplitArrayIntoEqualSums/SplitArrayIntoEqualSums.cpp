// SplitArrayIntoEqualSums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool SplitArray(vector<int>& nums, int& index);

int main()
{
    vector<int> nums = { 1 , 2 , 3 , 4 , 5 , 5 };
    int index = 0;

    cout << SplitArray(nums, index) << endl;
    cout << "Arrays are " << endl;
    for (int i = 0; i <= index; i++) {
        cout << " " << nums[i];
    }
    cout << endl;
    for (int i = index+1; i < nums.size(); i++) {
        cout << " " << nums[i];
    }
}

bool SplitArray(vector<int>& nums,int& index) {
    map<int, int> sums;

    // Calculate sume from right and left side and add to map
    // if both indices reach the end then not found
    int i = 0, j = 0;
    j = nums.size() - 1;  // last index
    int leftSum = 0, rightSum = 0;
    int N = nums.size() - 1;
    // Find total
    int total = 0;
    for (int i : nums)
        total += i;

    if (total % 2 != 0)   // Must be even
        return false;
    int target = total / 2;
    
    // Add from both sides to see if we find leftsum and rightsum as target
    for (int i = 0; i < nums.size(); i++) {
        leftSum += nums[i];

        if (leftSum == target) {
            // check for right sum
            int j = i + 1;
            for (int j = i + 1; j < nums.size(); j++) {
                rightSum += nums[j];
            }
            if (rightSum == target) {
                index = i;
                return true;
            }
            else {
                rightSum = 0;
            }
        }
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
