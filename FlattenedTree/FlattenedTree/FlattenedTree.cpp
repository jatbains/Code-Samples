// FlattenedTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}TreeNode;

void flatten(TreeNode* root);
TreeNode* flattenTree(TreeNode* root);

int main()
{
    std::cout << "Hello World!\n";
}

void flatten(TreeNode* root) {
    // flatten to a linked list
    // Inorder traversal into a new vector 

    root = flattenTree(root);

}
TreeNode* flattenTree(TreeNode* root) {

    if (root == NULL)
        return NULL;

    // If a leaf node then return
    if (root->left == NULL && root->right == NULL) {
        return root;
    }

    // flatten left subtree
    TreeNode* leftTail = flattenTree(root->left);
    // flatten right subtree
    TreeNode* rightTail = flattenTree(root->right);

    // If a left subtree is found then modify pointers
    if (leftTail != NULL) {
        leftTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    // return rightmost node after modifying pointers
    return rightTail == NULL ? leftTail : rightTail;

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
