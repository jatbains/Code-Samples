// Combinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k);
void findCombos(vector<vector<int>>& res, int k, int nums,int st,vector<int> digs, vector<int> comb);
void findPerms(vector<vector<int>>& res, int k, int nums, vector<int> digs, vector<int> comb);

int main()
{
    vector<vector<int>> res;

    res = combine(3, 1);
   
    for (vector<int> v : res) {
        for (int i : v) {
            cout << " " << i << " ";
        }
        cout << endl;
    }

  
   // std::cout << "Hello World!\n";
}

vector<vector<int>> combine(int n, int k) {
    // numbers 1...n  create a string oo vector of 1 to n
    // Recursively find combinations of k digits
    vector<vector<int>> result;
    vector<int> digs;
    for (int i = 1; i <= n; i++) {
        digs.push_back(i);
    }
    // Call into recursive function to create sub vectors
    vector<int> temp;
    
    findCombos(result, k, 0, 0, digs, temp);
    return result;
}
void findCombos(vector<vector<int>>& res, int k, int nums,int st, vector<int> digs, vector<int> comb) {
    if (nums == k) {
        res.push_back(comb);
        return;
    }

    for (int i = 0; i <= digs.size()-1; i++) {
        int x = digs[i];
        digs.erase(digs.begin() + i);
        
        comb.push_back(x);
        findCombos(res, k, nums + 1,i, digs, comb);
        comb.pop_back();
        digs.insert(digs.begin() + i, x);
    }
    return;
}

void findPerms(vector<vector<int>>& res, int k, int nums, vector<int> digs, vector<int> comb) {
    if (nums == k) {
        res.push_back(comb);
        return;
    }

    for (int i = 0; i <= k; i++) {
        int x = digs[i];
        digs.erase(digs.begin() + i);
        cout << digs.size() << endl;
        comb.push_back(x);
        findPerms(res, k, nums + 1, digs, comb);
        comb.pop_back();
        digs.insert(digs.begin() + i, x);
    }
    return;
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
