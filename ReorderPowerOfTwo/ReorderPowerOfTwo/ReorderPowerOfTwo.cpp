// ReorderPowerOfTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
bool reorderedPowerOf2(int N);
bool powerOfTwo(int N);
int numVec(vector<int>nums);
void permDigs(vector<int>& nums, vector<int> perms,vector<bool>& isPowTwo);

int main()
{
    cout << (reorderedPowerOf2(10) == true ? "Yes":"No") << endl;
}

bool reorderedPowerOf2(int N) {
    // Find all the digits into a vector
    vector<int> digits;
    vector<bool> isPower;
    while (N > 0) {
        digits.push_back(N % 10);
        N /= 10;
    }
  
    // Find all permutations of digits and see if power of 2

    vector<int> vals;
    permDigs(digits, vals, isPower);
    // if any combinations are true return true
    for (bool b : isPower) {
        if (b)
            return true;
    }
    return false;
}

void permDigs(vector<int>& nums, vector<int> perms,vector<bool>& isPowTwo) {
    if (nums.size() == 0) {
        // Check if power of two
        // ignore if first digit is 0
        if (perms[0] != 0) {
            int val = numVec(perms);
            isPowTwo.push_back(powerOfTwo(val));
        }
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        nums.erase(nums.begin() + i);
        perms.push_back(x);
        permDigs(nums, perms, isPowTwo);
        perms.pop_back();
        nums.insert(nums.begin() + i, x);
    }
 
}

int numVec(vector<int>nums) {
    int val = 0;
    for (int i : nums) {
        val = val * 10 + i;
    }
    return val;
}

bool powerOfTwo(int N) {
    int x = 1;

    while (x <= N) {
        if (x == N)
            return true;
        x *= 2;
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
