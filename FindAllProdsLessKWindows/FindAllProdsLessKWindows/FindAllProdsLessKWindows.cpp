// FindAllProdsLessKWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k);

int main()
{
    vector<int> nums = { 10, 5, 2, 6 };
    int k = 100;

    cout << "Num is " << numSubarrayProductLessThanK(nums, k) << endl;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    
    if (k <= 1) return 0;

    int prod = 1, ans = 0, left = 0;
    for (int right = 0; right < nums.size(); right++) {
        prod *= nums[right];
        while (prod >= k)
            prod /= nums[left++];
        ans += right - left + 1;
    }
    return ans;
}

/*
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }

*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
