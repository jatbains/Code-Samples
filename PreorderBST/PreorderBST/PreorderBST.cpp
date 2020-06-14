// PreorderBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
}TreeNode;

void ConstructBST(TreeNode*& root, vector<int>& pre, int& index, int key, int min, int max, int size);
void PreOrder(TreeNode* root);
void InOrder(TreeNode* root);

int main()
{
    TreeNode* root = nullptr;
    vector<int> vals = { 8, 5, 1, 7, 10, 12 };

    int size = vals.size();
    int index = 0;
    ConstructBST(root, vals, index, vals[0], INT_MIN, INT_MAX, size);
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
}

void InOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    InOrder(root->left);
    cout << " " << root->val;
    InOrder(root->right);
}

void PreOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << " " << root->val;
    PreOrder(root->left);
    PreOrder(root->right);
}

void ConstructBST(TreeNode*& root, vector<int>& pre, int& index, int key, int min, int max, int size)
{
    // Root
    if (index >= size)
        return;


    if (key > min && key < max) {
        root = new TreeNode(key);

        index++;

        if (index < size) {
            // Recurse for left and right
            ConstructBST(root->left, pre, index, pre[index], min, key, size);

            // Right tree
            ConstructBST(root->right, pre, index, pre[index], key, max, size);


        }

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
