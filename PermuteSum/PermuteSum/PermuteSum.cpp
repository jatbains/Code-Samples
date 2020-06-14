// PermuteSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);

void searchSum(vector<int>& nums, vector<vector<int>>& res, int target, vector<int> can, int digs);
void findAllNums(vector<int>& nums, int sum, vector<vector<int>>& res, vector<int> can, int i);

int main()
{
    vector<int> candidates = { 2, 3, 6, 7 };
    int  target = 7;

    vector<vector<int>> result;
    result = combinationSum(candidates, 7);
    for (vector<int> v : result) {
        for (int i : v) {
            cout << " " << i << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // Exhaustive search of permutations
    // Sum to find
    int len = candidates.size();
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<vector<int>> result;
    vector<int> can;
#if 0
    for (int i = 0; i < candidates.size(); i++) {
        searchSum(candidates, result, target, can, i);
    }
#endif
    findAllNums(candidates, target, result, can, 0);
    return result;

}

void findAllNums(vector<int>& nums, int sum, vector<vector<int>>& res, vector<int> can, int i) {
    if (sum < 0)    // Base case
        return;

    if (sum == 0) { // Add candidate
        res.push_back(can);
        return;
    }
    while (i < nums.size() && sum - nums[i] >= 0) {
        // Add to candidate
        can.push_back(nums[i]);
        findAllNums(nums, sum - nums[i], res, can, i);
        i++;
        can.pop_back();
    }
}

void searchSum(vector<int>& nums, vector<vector<int>>& res, int target, vector<int> can, int digs)
{
    // Check for the base case
    if (digs == can.size()) {
        // Check sum of digs
        int sum = 0;
        for (int i : can) {
            sum += i;
        }
        if (sum == target) {
            res.push_back(can);
        }
    }
    // else pick new nums
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        nums.erase(nums.begin() + i);
        can.push_back(x);
        searchSum(nums, res, target, can, digs);
        can.pop_back();
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
