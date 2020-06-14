// FindAllProdLessThanK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k);
void findAllProds(vector<int> nums, vector<int> subs,int size, int index, int prod, int& count);

int main()
{
    vector<int> nums = { 10, 5, 2, 6 };
    int k = 100;
    int count = 0;

    cout << "Count is " << numSubarrayProductLessThanK(nums, k) << endl;

}

int numSubarrayProductLessThanK(vector<int>& nums, int k) {

    // sort vector first.
    // start from right to left
    // need to find all permutations 
    int prod = 1;
    vector<int> subs;
    int count = 0;
    for (int i = 1; i <= nums.size(); i++) {
        findAllProds(nums, subs, i, 0, k, count);
    }
    return count;
   
}

void findAllProds(vector<int> nums, vector<int> subs, int size, int index, int prod, int& count) {

    if (subs.size() == size) {
        // test prod
        int mul = 1;
        for (int i : subs) {
            mul *= i;
            cout << " " << i;
        }
        cout << " mul " << mul << endl;
        if (mul < prod) {
            count++;
        }
    }
    for (int i = index; i < nums.size(); i++) {
        int x = nums[i];
        nums.erase(nums.begin() + i);
        subs.push_back(x);

        findAllProds(nums, subs, size, index + 1, prod, count);
        subs.pop_back();
        nums.insert(nums.begin() + i, x);
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
