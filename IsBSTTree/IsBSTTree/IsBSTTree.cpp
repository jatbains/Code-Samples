// IsBSTTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

int main()
{
    std::cout << "Hello World!\n";
}

bool isValidBST(TreeNode* root) {
    // Base case
    // bool isBST = CheckBST(root);
    bool isvalid = isBST(root, NULL, NULL);
    return isvalid;

}
bool isBST(TreeNode* root, TreeNode* l = NULL, TreeNode* r = NULL)
{
    // Base condition 
    if (root == NULL)
        return true;

    // if left node exist then check it has 
    // correct data or not i.e. left node's data 
    // should be less than root's data 
    if (l != NULL and root->val <= l->val)
        return false;

    // if right node exist then check it has 
    // correct data or not i.e. right node's data 
    // should be greater than root's data 
    if (r != NULL and root->val >= r->val)
        return false;

    // check recursively for every node. 
    return isBST(root->left, l, root) and
        isBST(root->right, root, r);
}

bool CheckBST(TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->left->val > root->val)
    {
        return false;
    }
    else if (root->right != NULL && root->val > root->right->val) {
        return false;
    }
    if (!CheckBST(root->left) || !CheckBST(root->right))
        return false;
    return true;
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
