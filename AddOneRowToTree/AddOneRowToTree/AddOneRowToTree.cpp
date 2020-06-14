// AddOneRowToTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* addOneRow(TreeNode* root, int v, int d);
void insertRow(TreeNode*& root, int v, int l, int d);

int main()
{
    std::cout << "Hello World!\n";
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {

    if (root == NULL && d == 0)  // Add to both left and right subtrees.
    {
        root = new TreeNode(v);
        return root;
    }
    if (d == 1) {
        TreeNode* temp = new TreeNode(v);
        temp->left = root;
        return temp;
    }
    // CHeck Depth == 0  Must link previous and next parts of tree.
    // Save previous pointers
    insertRow(root, v, 1, d);

    return root;
}

void insertRow(TreeNode*& root, int v, int l, int d) {
    if (root == NULL)
        return;

    if (l == d - 1) {
        TreeNode* left = root->left;

        root->left = new TreeNode(v);
        root->left->left = left;

        TreeNode* right = root->right;
        root->right = new TreeNode(v);
        // Link in the subtrees

        root->right->right = right;

        return;
    }
    else {
        insertRow(root->left, v, l + 1, d);
        insertRow(root->right, v, l + 1, d);

        return;
    }
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
