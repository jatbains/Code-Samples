// MaxBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

TreeNode* constructTree(vector<int> nums, int l, int r);
int max(vector<int> nums, int l, int r);

int main()
{
    vector<int> list = { 3, 2, 1, 6, 0, 5 };
    TreeNode* root = nullptr;

    root = constructTree(list, 0, list.size());
}

TreeNode* constructTree(vector<int> nums,int l, int r) {
    // if end of list done
    if (l == r)
        return nullptr;
    int max_i = max(nums, l, r);  
    // create node
    TreeNode *root = new TreeNode(nums[max_i]);
    root->left = constructTree(nums, l, max_i);
    root->right = constructTree(nums, max_i + 1, r);   // recursive
    return root;
}

int max(vector<int> nums, int l, int r) {
    // Search through vector and return index of maximum between l and r
    int max_i = l;
    int index = 0;
    for (int i = l; i < r; i++) {
        if (nums[i] > nums[max_i]) {
            max_i = i;
           
        }

    }
    return max_i;
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
