// MergeBinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* root = NULL;


    // Call function to recursively create a new tree
    root = mergedTree(root, t1, t2);
    return root;
}

TreeNode* allocNode(int x)
{
    TreeNode* temp = new TreeNode(x);
    return temp;
}

TreeNode* mergedTree(TreeNode* root, TreeNode* t1, TreeNode* t2)
{
    if ((t1 == NULL) && (t2 == NULL))
        return NULL;

    if (t1 == NULL)
    {
        root = allocNode(t2->val);
        return root;

    }
    if (t2 == NULL)
    {
        root = allocNode(t1->val);
        return root;

    }
    root = allocNode(t1->val + t2->val);
    // Search left and right
    root->left = mergedTree(root->left, t1->left, t2->left);
    root->right = mergedTree(root->right, t1->right, t2->right);
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
