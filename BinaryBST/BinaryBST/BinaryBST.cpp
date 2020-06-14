// BinaryBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

void RecurMakeTree(TreeNode*& root, vector<int>& nums, int l, int r);
void InOrderTraversal(TreeNode* root);

int main()
{
    vector<int> vals = { -10, -3, 0, 5, 9 };
    TreeNode *root = nullptr;

    cout << "Create Tree" << endl;

    RecurMakeTree(root, vals, 0, vals.size() - 1);
    InOrderTraversal(root);

    std::cout << "Hello World!\n";
}

void InOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    InOrderTraversal(root->left);
    cout << "Value is " << root->val << endl;
    InOrderTraversal(root->right);
}

void RecurMakeTree(TreeNode*& root,vector<int>& nums, int l, int r) {
    if (l > r)
        return;   // all done
    int mid = l + (r - l) / 2;
    int val = nums[mid];
    if (root == nullptr) {
        root = new TreeNode(val);
    }

    // Recur to the left and right side of tree
    RecurMakeTree(root->left, nums, l, mid - 1);
    RecurMakeTree(root->right, nums, mid + 1, r);
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
