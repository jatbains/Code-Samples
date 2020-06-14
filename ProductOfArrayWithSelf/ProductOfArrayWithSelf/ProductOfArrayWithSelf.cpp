// ProductOfArrayWithSelf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums);

int main()
{
    vector<int> nums = { 4,5,1,8,2 };
    vector<int> result;
    result = productExceptSelf(nums);
}


vector<int> productExceptSelf(vector<int>& nums) {
    // FInd complete product and then divide by individual numbers
    // no division
    vector<int> prod;
    int len = nums.size();
    prod.resize(len);
    prod[0] = 1;
    vector<int> left(len);
    vector<int> right(len);
    left[0] = 1;
    right[len - 1] = 1;
    for (int i = 1; i < len; i++) {
        prod[i] = prod[i - 1] * nums[i - 1];
        left[i] = left[i - 1] * nums[i - 1];
    }

    // Right side
    int R = 1;
    for (int i = len - 1; i >= 0; i--) {
        prod[i] = prod[i] * R;
        R = R * nums[i];
    }
    for (int i = len - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i<len; i++) {
        cout << "Left prod " << left[i] << endl;
    }
    for (int i = len - 1; i >= 0; i--) {
        cout << "Right prod " << right[i] << endl;
    }
    return prod;
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
