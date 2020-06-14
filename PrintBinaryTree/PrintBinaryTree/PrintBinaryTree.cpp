// PrintBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

using namespace std;

int getHeight(TreeNode* root);
int getMaxWidth(TreeNode* root, int height);
int getWidth(TreeNode* root, int level);
void fillList(vector<vector<string>>& out, TreeNode* root, int row, int left, int right);
vector<vector<string>> printTree(TreeNode* root);
void InsertNode(TreeNode*& root, int x);
void PrintInOrder(TreeNode* root);

int main()
{
    vector<vector<string>> pTree;
    TreeNode* root = nullptr;
    for (int i = 0; i < 10; i++) {
        InsertNode(root, rand() % 23);
    }

    PrintInOrder(root);
    cout << endl;
    pTree = printTree(root);

    for (vector<string> v : pTree) {
        for (string s : v)
            cout << s << " ";
        cout << endl;
    }
}

void PrintInOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    PrintInOrder(root->left);
    cout << " " << root->val << " ";
    PrintInOrder(root->right);
}

bool isComplete(TreeNode* root, int index, int count) {
    if (root == NULL)
        return true;

    if (index >= count)
        return (false);

    // Recur for left and right subtrees 
    return (isComplete(root->left, 2 * index + 1, count) &&
        isComplete(root->right, 2 * index + 2, count));
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    // Duplicate subtrees find nodes that are duplicate and check for the node structure.

    // One method to find duplicate nodes
    // O(n^2) compare each node against all others
    // TreeNode root, root->left , root->right
    // If duplicate is found then check for same subtrees
    unordered_map<string, int> vals;
    vector<TreeNode*> res;
    inOrderTraverse(root, vals, res);
    return res;
}

string inOrderTraverse(TreeNode* root, unordered_map<string, int>& dups, vector<TreeNode*>& res) {
    if (root == NULL)
        return "";


    string str = "(";
    str += inOrderTraverse(root->left, dups, res);
    str += to_string(root->val);
    str += inOrderTraverse(root->right, dups, res);
    str += ")";

    // Subtree already present (Note that we use 
    // unordered_map instead of unordered_set 
    // because we want to print multiple duplicates 
    // only once, consider example of 4 in above 
    // subtree, it should be printed only once. 
    if (dups[str] == 1)
        res.push_back(root);

    dups[str]++;

    return str;


}

int SizeOfTree(TreeNode* root) {
    if (root == NULL)
        return 0;

    return (1 + SizeOfTree(root->left) + SizeOfTree(root->right));
}

void InsertNode(TreeNode*& root, int x) {
    if (root == nullptr) {
        root = new TreeNode(x);
        return;
    }
    if (x < root->val) {  // Insert left
        InsertNode(root->left, x);
    }
    else {
        InsertNode(root->right, x);
    }
}

vector<vector<string>> printTree(TreeNode* root) {
    // Find the width and height of the tree
    // Process the tree level by level - or use a queue
    vector<vector<string>> result;
    vector<string> row;
    int height = getHeight(root);
    int width = getMaxWidth(root, height);
    // Process the tree level by level - or use a queue

    result.resize(height);
    // resize each colun
    vector<string>::iterator it;
    for (auto& it : result) {
        it.resize((1 << height) - 1);
    }
 
    // Fill in this with call to function
    fillList(result, root, 0, 0, result[0].size());
    return result;
}

void fillList(vector<vector<string>>& out, TreeNode* root, int row, int left, int right) {
    if (root == NULL)
        return;
    out[row][(left + right) / 2] = "" + to_string(root->val);
    fillList(out, root->left, row + 1, left, (left + right) / 2);
    fillList(out, root->right, row + 1, (left + right + 1) / 2, right);
}

int getHeight(TreeNode* root) {
    if (root == NULL)
        return 0;

    int lh = getHeight(root->left) + 1;
    int rh = getHeight(root->right) + 1;

    return (lh > rh ? lh : rh);
}

int getMaxWidth(TreeNode* root, int height) {
    int maxWidth = 0;

    for (int i = 1; i <= height; i++) {
        int width = getWidth(root, i);
        if (width > maxWidth)
            width = maxWidth;
    }
    return maxWidth;
}

int getWidth(TreeNode* root, int level) {
    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    else if (level > 1)
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
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
