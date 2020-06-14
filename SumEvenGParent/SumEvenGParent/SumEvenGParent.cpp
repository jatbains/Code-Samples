// SumEvenGParent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

void FindGPSum(TreeNode* node, TreeNode* par, TreeNode* gPar, int& sum);
void findSum(TreeNode* root, TreeNode* parent, map<TreeNode*, TreeNode*>& parents, int& count);

int main()
{
    std::cout << "Hello World!\n";
}

int sumEvenGrandparent(TreeNode* root) {
    // Check if value of node is even
    // if even then find all the grandchildren recursively and add up value
    int sum = 0;
    map<TreeNode*, TreeNode*> parents;
    // Call helper function to calc value
    //findSum(root, NULL, parents,sum);
    FindGPSum(root, NULL, NULL, sum);
    return sum;
}

void FindGPSum(TreeNode* node, TreeNode* par, TreeNode* gPar, int& sum) {
    if (node == NULL)
        return;

    if (gPar != NULL)
        if (gPar->val % 2 == 0)
            sum += node->val;

    // Search the tree
    FindGPSum(node->left, node, par, sum);
    FindGPSum(node->right, node, par, sum);
}

void findSum(TreeNode* root, TreeNode* parent, map<TreeNode*, TreeNode*>& parents, int& count) {
    // Base case
    if (root == NULL)
        return;

    // Check to see if grandparent of node val is even

    if (parent && parents.count(parent) && parents[parent] && parents[parent]->val % 2 == 0) {
        // Check val of parent
        count += parents[parent]->val;
    }
    // Add it to the map
    parents[root] = parent;
    findSum(root->left, root, parents, count);
    findSum(root->right, root, parents, count);
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
