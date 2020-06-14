// BalancedBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

using namespace std;
void insertNode(TreeNode*& root, int x);
void preOrder(TreeNode* root, vector<int>& vals);
void inOrder(TreeNode* root, vector<int>& vals);
void postOrder(TreeNode* root, vector<int>& vals);
void printVals(vector<int> vals);
int depthOfTree(TreeNode* root);
void balancedBST(TreeNode*& root, vector<int>& vals, int left, int right);
int sumEvenGrandparent(TreeNode* root);
void calcSum(TreeNode* root, bool parent, bool gParent, int& count);
void findSum(TreeNode* root, TreeNode* parent, map<TreeNode*, TreeNode*>& parents, int& count);
void dfsSearch(TreeNode* root);

int main()
{
    vector<int> nodes;
    TreeNode* root = nullptr;
    TreeNode* balanced = nullptr;

    for (int i = 0; i < 20; i++) {
        insertNode(root, rand() % 111);
    }
    cout << "Depth is " << depthOfTree(root) << endl;
    preOrder(root, nodes);
    cout << "PreOrder" << endl;
    printVals(nodes);
    nodes.clear();
    postOrder(root, nodes);
    cout << "PostOrder" << endl;
    printVals(nodes);
    nodes.clear();
    cout << "InOrder" << endl;
    inOrder(root, nodes);
    printVals(nodes);

    // Create a balanced tree
    balancedBST(balanced, nodes, 0, nodes.size() - 1);
    nodes.clear();
    inOrder(balanced, nodes);
    cout << endl << "Balanced In Order " << endl;
    printVals(nodes);
    cout << "Depth of Balanced BST " << depthOfTree(balanced) << endl;

    cout << "Sum of Even " << sumEvenGrandparent(balanced) << endl;
    cout << endl;
    dfsSearch(balanced);
}

void dfsSearch(TreeNode* root) {
    queue<TreeNode*> nodes;
    nodes.push(root);
    int level = 1;

    while (!nodes.empty()) {
        int nodeCount = nodes.size();
        cout << "Level is " << level << endl;
        while (nodeCount > 0) {
            TreeNode* temp = nodes.front();
            cout << "  " << temp->val;
            nodes.pop();

            if (temp->left != nullptr)
                nodes.push(temp->left);
            if (temp->right != nullptr)
                nodes.push(temp->right);
            nodeCount--;
        }
        level++;
        cout << endl;
    }

}

int sumEvenGrandparent(TreeNode* root) {
    // Check if value of node is even
    // if even then find all the grandchildren recursively and add up value
    int sum = 0;
    map<TreeNode*, TreeNode*> parents;
    // Call helper function to calc value
    calcSum(root, false, false, sum);
    cout << "Method 1 sum " << sum << endl;
    sum = 0;
    findSum(root, nullptr, parents, sum);
    return sum;
}

void findSum(TreeNode* root,TreeNode* parent, map<TreeNode*, TreeNode*>& parents, int& count) {
    // Base case
    if (root == nullptr)
        return;

    // Check to see if grandparent of node val is even
    
    if ((parent != nullptr) && parents.count(parent) && parents[parent] && parents[parent]->val % 2 == 0) {
        // Check val of parent
        count += parents[parent]->val;
    }
    // Add it to the map
    parents[root] = parent;
    findSum(root->left, root, parents, count);
    findSum(root->right, root, parents, count);
}

void calcSum(TreeNode* root, bool parent, bool gParent, int& count) {
    if (root == NULL)
        return;

    if (gParent) {
        count += root->val;

        calcSum(root->left, root->val % 2 == 0, parent, count);
        calcSum(root->right, root->val % 2 == 0, parent, count);
    }
}


void balancedBST(TreeNode*& root, vector<int>& vals, int left, int right) {
    // Base case
    if (left > right)   // finished
        return; 

    int mid = left + (right - left) / 2;
    root = new TreeNode(vals[mid]);
    // Recur left and right
    balancedBST(root->left, vals, left, mid - 1);
    balancedBST(root->right, vals, mid + 1, right);
}

int depthOfTree(TreeNode* root) {
    if (root == nullptr) // empty tree
        return 0;

    int lh = 1 + depthOfTree(root->left);
    int rh = 1 + depthOfTree(root->right);
    return (lh > rh ? lh : rh);
}

void printVals(vector<int> vals) {
    for (int i : vals)
        cout << " " << i;
    cout << endl;
}

void insertNode(TreeNode*& root, int x) {
    if (root == nullptr) {
        root = new TreeNode(x);
        return;
    }
    if (x < root->val) { // Insert left
        insertNode(root->left, x);
    }
    else {
        insertNode(root->right, x);
    }
}
void preOrder(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;
    vals.push_back(root->val);
    preOrder(root->left, vals);
    preOrder(root->right, vals);
}
void inOrder(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;
    inOrder(root->left, vals);
    vals.push_back(root->val);
    inOrder(root->right, vals);
}
void postOrder(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;
    postOrder(root->left, vals);
    postOrder(root->right, vals);
    vals.push_back(root->val);
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
