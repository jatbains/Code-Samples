// CombinationSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void searchSum(vector<vector<int>>& result, int target, vector<int>& nums, vector<int>& cand, int digs);

int main()
{
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;

    vector<vector<int>> result;
    result = combinationSum(candidates, target);

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
    vector<vector<int>> result;
    vector<int> attempt;
    for (int i = 1; i <= candidates.size(); i++) {
        searchSum(result, target, candidates, attempt,i);
    }
   
    return result;
}

void searchSum(vector<vector<int>>& result, int target, vector<int>& nums, vector<int>& cand,int digs) {
    // Check for the base case
    if (cand.size() == digs ){
        // Check sum of digs
        int sum = 0;
        cout << endl;
        for (int i : cand) {
            cout << " " << i << " ";
            sum += i;
        }
        cout << endl;
        if (sum == target) {
            result.push_back(cand);
        }
    }
    // else pick new nums
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        nums.erase(nums.begin() + i);
        cand.push_back(x);
        searchSum(result, target, nums, cand, digs);
        cand.pop_back();
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
