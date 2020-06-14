// ZigZagTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

vector<vector<int>> zigzagLevelOrder(TreeNode* root);
void zigzagRecur(TreeNode* root, int level, vector<int>& row, int dep);
int depth(TreeNode* root);
void zigzagLtoR(TreeNode* root, int level, vector<int>& row, int dep);
void zigzagRtoL(TreeNode* root, int level, vector<int>& row, int dep);

int main()
{
    std::cout << "Hello World!\n";
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // if level is odd or even we switch left to right vice versa
    //  process either right child or left child
    vector<int> level;
    int dep = depth(root);
    bool isEven = false;
    vector<vector<int>> result;
    for (int i = 0; i < dep; i++) {
        if (isEven) {
            zigzagRtoL(root, 0, level, i);
            isEven = false;
        }
        else if (!isEven) {
            zigzagLtoR(root, 0, level, i);
            isEven = true;
        }
        result.push_back(level);
        level.clear();
    }
    return result;
}

void zigzagLtoR(TreeNode* root, int level, vector<int>& row, int dep) {
    if (root == NULL)
        return;
    if (level == dep) {
        row.push_back(root->val);
    }

    zigzagLtoR(root->left, level + 1, row, dep);
    zigzagLtoR(root->right, level + 1, row, dep);
    
}

void zigzagRtoL(TreeNode* root, int level, vector<int>& row, int dep) {

    if (root == NULL)
        return;
    if (level == dep) {
        row.push_back(root->val);
    }
  
    zigzagRtoL(root->right, level + 1, row, dep);
    zigzagRtoL(root->left, level + 1, row, dep);
 
}

void zigzagRecur(TreeNode* root, int level, vector<int>& row, int dep) {

    if (root == NULL)
        return;
    if (level == dep) {
        row.push_back(root->val);
    }

    if ((level + 1) % 2 == 1) {
        zigzagRecur(root->right, level + 1, row, dep);
        zigzagRecur(root->left, level + 1, row, dep);
    }
    else {
        zigzagRecur(root->left, level + 1, row, dep);
        zigzagRecur(root->right, level + 1, row, dep);
    }

}

int depth(TreeNode* root) {
    if (root == NULL)
        return 0;

    int lh = depth(root->left) + 1;
    int rh = depth(root->right) + 1;

    return lh > rh ? lh : rh;
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
