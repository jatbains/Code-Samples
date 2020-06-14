// isSymmetricTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct  TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main()
{
    std::cout << "Hello World!\n";
}

bool isSymmetric(TreeNode* root) {
    // Recursively check that left is equal to right
    return isSymmRecur(root, root);
}

bool isSymmRecur(TreeNode* r1, TreeNode* r2) {

    if (r1 == NULL && r2 == NULL)
        return true;

    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
        return false;

    if (r1->val != r2->val)
        return false;

    return isSymmRecur(r1->left, r2->right) && isSymmRecur(r1->right, r2->left);
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
