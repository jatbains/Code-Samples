// RemoveLeafNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

int main()
{
    std::cout << "Hello World!\n";
}

TreeNode* removeLeafTarget(TreeNode*& node, int target) {
    if (node == NULL)
        return NULL;

    node->left = removeLeafTarget(node->left, target);
    node->right = removeLeafTarget(node->right, target);

    // Leaf is if left and right pointers are null
    if (node->val == target && node->left == NULL && node->right == NULL) {
        // check target
        return NULL;
    }
    return node;
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
