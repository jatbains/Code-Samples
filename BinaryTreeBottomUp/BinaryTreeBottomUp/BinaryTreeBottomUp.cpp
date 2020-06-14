// BinaryTreeBottomUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

}TreeNode;

TreeNode* AllocNode(int x);
void InsertNode(TreeNode*& root, int x);
void PrinInOrder(TreeNode* root);
int depthOfTree(TreeNode* root);
void GetLevels(TreeNode* root, vector<int>& row, int depth, int level);
vector<vector<int>> levelOrderBottom(TreeNode* root);

int main()
{
    //  [3,9,20,null,null,15,7],
    TreeNode* root = nullptr;

    // Build Tree
    InsertNode(root, 9);
    InsertNode(root, 3);
    InsertNode(root, 20);
    InsertNode(root, 15);
    InsertNode(root, 7);

    PrinInOrder(root);
}


TreeNode* AllocNode(int x)
{
    TreeNode* temp = new TreeNode(x);
    return temp;
}

void InsertNode(TreeNode*& root, int x)
{
    if (root == nullptr)
    {
        root = AllocNode(x);
        return;
    }
    
    if (x < root->val)
    {
        InsertNode(root->left, x);
    }
    else
    {
        InsertNode(root->right, x);
    }
}

void PrinInOrder(TreeNode* root)
{
    if (root == nullptr)
        return;
    PrinInOrder(root->left);
    cout << " Node " << root->val << endl;
    PrinInOrder(root->right);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int depth = depthOfTree(root);
    vector<vector<int>>* treeL = new vector<vector<int>>;
    vector<int> level;
    // Go from bottom up
    for (int i = depth; i >= 0; i--)
    {
        GetLevels(root, level, depth, i);
        treeL->push_back(level);
        level.clear();
    }

    return *treeL;
}

void GetLevels(TreeNode* root, vector<int>& row, int depth, int level)
{
    if (root == NULL)
        return;

    if (level == depth)
    {
        row.push_back(root->val);
    }

    // Recur down tree
    GetLevels(root->left, row, depth - 1, level);
    GetLevels(root->right, row, depth - 1, level);
}

int depthOfTree(TreeNode* root)
{
    if (root == NULL)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    if (root->left == nullptr)
        return depthOfTree(root->right) +1;

    if (root->right == nullptr)
        return depthOfTree(root->left) +1;

    int lh = 1 + depthOfTree(root->left);
    int rh = 1 + depthOfTree(root->right);

    return (lh > rh ? lh : rh);
  //  return max(depthOfTree(root->left), depthOfTree(root->right)) + 1;
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
