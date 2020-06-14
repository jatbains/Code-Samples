// SumOfDeepestNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
}TreeNode;


using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}



int deepestLeavesSum(TreeNode* root) {

    int depth = depthOfTree(root);

    int sum = 0;
    // Find sum of nodes at level depth
    sumOfDeepNodes(root, 1, depth, sum);

    return sum;

}


void sumOfDeepNodes(TreeNode* root, int level, int depth, int& sum)
{
    if (root == NULL)
        return;

    if (level == depth)
        sum += root->val;

    // Search left and right sutrees
    sumOfDeepNodes(root->left, level + 1, depth, sum);
    sumOfDeepNodes(root->right, level + 1, depth, sum);
}



int depthOfTree(TreeNode* root)
{
    if (root == NULL)
        return 0;

    int lh = depthOfTree(root->left) + 1;
    int rh = depthOfTree(root->right) + 1;

    return (lh > rh ? lh : rh);
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
