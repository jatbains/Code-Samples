// FindMinDistanceBSTNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void InOrder(TreeNode* root, vector<int>& nodes);
int minDiffInBST(TreeNode* root);
void findMin(TreeNode* root, int& minVal);

int main()
{
    std::cout << "Hello World!\n";
}

int minDiffInBST(TreeNode* root) {
    int min = INT_MAX;
    int diff = 0;
    int prev = 0;
    vector<int> nodes;
    // findMin(root,min);
    // Alternative Do an inorder traversal and and create a vector look for min between adjacent nodes
    InOrder(root, nodes);
    // Search vector
    prev = nodes[0];
    for (int i = 1; i < nodes.size(); i++) {

        cout << i << " ";
        diff = abs(nodes[i] - prev);
        if (diff < min)
            min = diff;
        prev = nodes[i];
    }

    return min;

}

void InOrder(TreeNode* root, vector<int>& nodes) {
    if (root == NULL)
        return;

    InOrder(root->left, nodes);
    nodes.push_back(root->val);
    InOrder(root->right, nodes);
}

void findMin(TreeNode* root, int& minVal) {
    if (root == NULL)
        return;

    if (root->left != NULL || root->right != NULL) {
        int ld = INT_MAX, rd = INT_MAX;

        if (root->left != NULL) {
            ld = abs(root->left->val - root->val);
            cout << ld << " ";
        }
        if (root->right != NULL) {
            rd = abs(root->right->val - root->val);
            cout << rd << " ";
        }
        int diff = ld < rd ? ld : rd;
        cout << diff << " ";
        if (diff < minVal)
            minVal = diff;
    }
    // recur
    findMin(root->left, minVal);
    findMin(root->right, minVal);
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
