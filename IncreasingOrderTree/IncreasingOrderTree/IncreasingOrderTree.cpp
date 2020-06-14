// IncreasingOrderTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

TreeNode* increasingBST(TreeNode* root);
TreeNode* increasingOrder(TreeNode* root, int val);
void inOrderVals(TreeNode* root, vector<int>& vals);

int main()
{
    std::cout << "Hello World!\n";
}
TreeNode* increasingBST(TreeNode* root) {
    // Get the Inorder vector of values
    // Use this to create a new tree
    TreeNode* inOrder = NULL;
    vector<int> values;
    inOrderVals(root, values);
    // Make new Tree
    for (int i = 0; i < values.size(); i++)
    {

        // inOrder = insertTree(inOrder, values[i]);
        inOrder = increasingOrder(inOrder, values[i]);
    }
    return inOrder;
}

TreeNode* increasingOrder(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* temp = new TreeNode(val);
        return temp;
    }
    TreeNode* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->right = new TreeNode(val);
    return root;
}

void inOrderVals(TreeNode* root, vector<int>& vals)
{
    if (root == NULL)
        return;
    inOrderVals(root->left, vals);
    cout << root->val << " ";
    vals.push_back(root->val);
    inOrderVals(root->right, vals);
}

TreeNode* insertTree(TreeNode* root, int x)
{
    if (root == NULL)
    {
        root = new TreeNode(x);
        return root;
    }
    if (x < root->val) {
        root->left = insertTree(root->left, x);  // insert left
    }
    else {
        root->right = insertTree(root->right, x);
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
