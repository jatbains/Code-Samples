// Subsets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
void recurbackPerm(vector<int> nums, vector<int> out, int index,vector<vector<int>>& result);
vector<vector<int>> subsets(vector<int>& nums);
void recurbackComb(vector<int> nums, vector<int> out, int index, int first, vector<vector<int>>& result);
vector<vector<int>> subsetsComb(vector<int>& nums);

int main()
{
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> result;

    result = subsets(nums);

    for (vector<int> v : result) {
        for (int i : v) {
            cout << " " << i << " ";
        }
        cout << endl;
    }

    result = subsetsComb(nums);
    for (vector<int> v : result) {
        for (int i : v) {
            cout << " " << i << " ";
        }
        cout << endl;
    }

    //std::cout << "Hello World!\n";
}
vector<vector<int>> subsets(vector<int>& nums) {
    // create a vector of vectors
    vector<vector<int>> result;
    vector<int> out;
    // Loop through all numbers in vector
    for (unsigned int i = 0; i <= nums.size(); i++) {
        // Call recursive function
        recurbackPerm(nums, out, i, result);
        out.clear();
    }
    return result;
}
void recurbackPerm(vector<int> nums, vector<int> out, int index,vector<vector<int>>& result) {
    // base case when out has size of index
    if (out.size() == index) {
        result.push_back(out);
        return;
    }

    // Recurrent portion
    for (unsigned int i = 0; i < nums.size(); ++i) {
        int val = nums[i];
        nums.erase(nums.begin() + i);
        out.push_back(val);
        recurbackPerm(nums, out, index, result);
        out.pop_back();
        nums.insert(nums.begin() + i, val);
    }
}

vector<vector<int>> subsetsComb(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    vector<int> out;

    for (int k = 0; k < n + 1; ++k) {
       // backtrack(0, new ArrayList<Integer>(), nums);
        recurbackComb(nums, out, k, 0, result);
    }
    return result;
}
void recurbackComb(vector<int> nums, vector<int> out, int index,int first, vector<vector<int>>& result)
{
    // if the combination is done
    if (out.size() == index) {
        result.push_back(out);
        return;
    }

    for (int i = first; i < nums.size(); ++i) {
        // add i into the current combination
        out.push_back(nums[i]);
        // use next integers to complete the combination
        recurbackComb(nums, out, index, i+1, result);
        // backtrack
        out.pop_back();  
    }
}
/*
class Solution {
  List<List<Integer>> output = new ArrayList();
  int n, k;

  public void backtrack(int first, ArrayList<Integer> curr, int[] nums) {
    // if the combination is done
    if (curr.size() == k)
      output.add(new ArrayList(curr));

    for (int i = first; i < n; ++i) {
      // add i into the current combination
      curr.add(nums[i]);
      // use next integers to complete the combination
      backtrack(i + 1, curr, nums);
      // backtrack
      curr.remove(curr.size() - 1);
    }
  }

  public List<List<Integer>> subsets(int[] nums) {
    n = nums.length;
    for (k = 0; k < n + 1; ++k) {
      backtrack(0, new ArrayList<Integer>(), nums);
    }
    return output;
  }
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
