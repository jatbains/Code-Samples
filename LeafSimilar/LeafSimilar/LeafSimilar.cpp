// LeafSimilar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
}TreeNode;

bool leafSimilar(TreeNode* root1, TreeNode* root2);
void getLeaves(TreeNode* root, vector<int>& leaves);

int main()
{
    std::cout << "Hello World!\n";
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    // Get the leaves of the two binary trees and then compare them
    vector<int> leaf1;
    vector<int> leaf2;
    // Get leaves
    getLeaves(root1, leaf1);
    getLeaves(root2, leaf2);

    if (leaf1.size() != leaf2.size())
        return false;

    for (int i = 0; i < leaf1.size(); i++)
    {
        if (leaf1[i] != leaf2[i])
            return false;
    }
    // the same
    return true;

}

void getLeaves(TreeNode* root, vector<int>& leaves)
{
    if (root == NULL)
        return;
    if ((root->left == NULL) && (root->right == NULL)) {
        // leaf node
        leaves.push_back(root->val);
    }
    // Search leaft and right subtrees
    getLeaves(root->left, leaves);
    getLeaves(root->right, leaves);
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
