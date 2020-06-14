// TrimBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

int main()
{
    std::cout << "Hello World!\n";
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
    // Trim between L and R inclusive
    root = trimBSTRecur(root, L, R);
    return root;

}

TreeNode* trimBSTRecur(TreeNode* root, int L, int R)
{
    if (root == NULL)
        return NULL;

    // Fix left and right subtrees

    root->left = trimBSTRecur(root->left, L, R);
    root->right = trimBSTRecur(root->right, L, R);


    if (root->val < L)
    {
        TreeNode* rChild = root->right;

        return rChild;

    }
    if (root->val > R)
    {
        TreeNode* lChild = root->left;

        return lChild;
    }
    return root;
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
