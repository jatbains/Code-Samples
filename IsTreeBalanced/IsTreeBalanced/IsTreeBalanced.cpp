// IsTreeBalanced.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;



int main()
{
    std::cout << "Hello World!\n";
}

bool isBalanced(TreeNode* root) {
    // Find the left height and the right height
    // Compare the difference if greater than 1 then false else true

    if (root == NULL)
        return true;    // empty tree

    if (root->left == NULL && root->right == NULL)
        return true;

    return isBalancedTree(root);

}

bool isBalancedTree(TreeNode* root)
{
    if (root == NULL) {
        return true;
    }

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    // Recursively check all subtrees.
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    else
        return false;
}

int heightOfTree(TreeNode* root)
{
    if (root == NULL)
        return 0;

    int lh = heightOfTree(root->left) + 1;
    int rh = heightOfTree(root->right) + 1;


    return (lh > rh ? lh : rh);
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
