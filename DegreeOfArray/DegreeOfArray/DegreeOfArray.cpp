// DegreeOfArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int arrayDeg(vector<int> nums,int& val);

int main()
{
    vector<int> nums = { 1, 2, 2, 3, 1};
    int val = 0;

    cout << "Degree is " << arrayDeg(nums, val) << endl;
    cout << "Number is " << val << endl;

    int l = 0, r = (nums.size() - 1) / 2;
    l = r - 1;
    bool lFound = false, rFound = false;

    int low = 0, high = 0;
    while (l>0 &&  r<nums.size()-1) {
        if (nums[l] == val)
            if (!lFound) {
                low = l;
                lFound = true;
            }
        if (nums[r] == val)
            if (!rFound) {
                high = r;
                rFound = true;
            }
        l--;
        r++;
    }
    cout << "Minimum length " << high - low + 1 << endl;
}

int arrayDeg(vector<int> nums,int& val) {
    map<int, int> freq;
    int max = 0;
    for (int i : nums) {
        freq[i]++;
    }
    map<int, int>::iterator it = freq.begin();
    while (it != freq.end()) {
        if (it->second > max) {
            max = it->second;
            val = it->first;
        }
        it++;
    }
    return max;
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
