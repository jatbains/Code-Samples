// KNodeInTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

using namespace std;
vector<int> distanceK(TreeNode* root, TreeNode* target, int K);
void FindNodeList(TreeNode* root, int depth, int level, int k, int tarVal, vector<int>& nodes);
void FindKNodes(TreeNode* root, TreeNode* target, int& depth, int level, int& tarVal);
int HeightofTree(TreeNode* root);
void InOrder(TreeNode* root);
void InsertNode(TreeNode*& root, int x);


int main()
{
    TreeNode* root = nullptr;
    // Create a tree
    for (int i = 0; i <= 10; i++) {
        InsertNode(root, rand() % 101);
    }
    for (int j = 10; j >= 0; j--) {
        InsertNode(root, rand() % 51);
    }
    InOrder(root);

    int height = HeightofTree(root);
    cout << "Height is " << height << endl;

}

void InOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    InOrder(root->left);
    cout << "Node is " << root->val << " " << endl;
    InOrder(root->right);
}

void InsertNode(TreeNode*& root, int x) {
    // Base case
    if (root == nullptr) {
        root = new TreeNode(x);
        return;
    }
    // INsert left or right
    if (x < root->val) {
        InsertNode(root->left, x);
    }
    else {
        InsertNode(root->right, x);
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    int depth = HeightofTree(root);
    int level = 0;
    int tarVal = 0;
    FindKNodes(root, target, level, 1, tarVal);
    vector<int> nodes;
    // distance away from depth abs(depth-k == 0)
    FindNodeList(root, level, 1, K, tarVal, nodes);
    return nodes;

}
void FindNodeList(TreeNode* root, int depth, int level, int k, int tarVal, vector<int>& nodes) {
    // Base case
    if (root == NULL)
        return;
    if (abs(depth - level) == k || (level == k)) {
        if (root->val != tarVal)
            nodes.push_back(root->val);
    }
    // Search left and right
    FindNodeList(root->left, depth, level + 1, k, tarVal, nodes);
    FindNodeList(root->right, depth, level + 1, k, tarVal, nodes);
}

void FindKNodes(TreeNode* root, TreeNode* target, int& depth, int level, int& tarVal) {
    // Base case
    if (root == NULL)
        return;

    // Test for target node
    if (root == target) {
        tarVal = root->val;
        depth = level;
    }
    // Search left and right
    FindKNodes(root->left, target, depth, level + 1, tarVal);
    FindKNodes(root->right, target, depth, level + 1, tarVal);
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    // original and cloned trees  
    if (original == NULL || cloned == NULL)
        return NULL;                             // not found

    if (original == target) {   // Return pointer to cloned
        TreeNode* copy = cloned;
        return copy;
    }

    // Continue searching
    TreeNode* lcopy = getTargetCopy(original->left, cloned->left, target);
    TreeNode* rcopy = getTargetCopy(original->right, cloned->right, target);

    if (lcopy == NULL && rcopy == NULL)
        return NULL;
    else if (lcopy != NULL)
        return lcopy;

    return rcopy;
}

// DFS or BFS 
int HeightofTree(TreeNode* root) {
    if (root == NULL)
        return 1;

    int lh = HeightofTree(root->left) + 1;
    int rh = HeightofTree(root->right) + 1;

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
