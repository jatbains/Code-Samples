// TreeToPriorityQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int pri;             // Priority is based on height from bottom
    TreeNode(int x) : val(x), left(nullptr), right(nullptr),pri(0) {}
}TreeNode;

typedef pair<int, TreeNode*> tnode;

TreeNode* AllocNode(int x);
void InsertNode(TreeNode*& root, int x);
void InOrderTree(TreeNode* root);
int depthOfTree(TreeNode* root);
void InorderPrio(TreeNode* root);
void priorities(TreeNode* root, int depth);
void priorityRecur(TreeNode* root, int depth, int d, int l);
void AddtoQueue(priority_queue<tnode,vector<tnode>, greater<tnode>>& pq, TreeNode* root);

int main()
{
    TreeNode* root = nullptr;
    priority_queue<tnode,vector<tnode>, greater<tnode> >  pq;

    for (int i = 0; i <= 20; i++) {
        InsertNode(root, rand() % 101);
    }
   // print out tree
    InOrderTree(root);
    cout << "Depth is " << depthOfTree(root) << endl;
    int depth = depthOfTree(root);
    priorities(root, depth);
    // Update priorities
    InorderPrio(root);
    // Put into queue
    AddtoQueue(pq, root);
    // Print out priority queue
    cout << endl;
    cout << " Nodes sorted in order of priority " << endl;
    while (!pq.empty()) {
        pair<int,TreeNode*> el = pq.top();
        cout << " Node is " << el.second->val << " Priority is " << el.first << endl;
        pq.pop();
    }
}

void AddtoQueue(priority_queue<tnode, vector<tnode>, greater<tnode>>& pq, TreeNode* root) {
    if (root == nullptr)
        return;  // Done
    // In order
    AddtoQueue(pq, root->left);
    pq.push(make_pair(root->pri, root));
    AddtoQueue(pq, root->right);

}

void priorities(TreeNode* root,int depth) {

    for (int i = 0; i <= depth; i++) {
        priorityRecur(root, depth, i, 0);
    }
}

void priorityRecur(TreeNode* root,int depth,int d, int l) {

    if (root == nullptr)
        return;

    if (d == l){
        root->pri = depth - l;
    }
    // Recur down tree
    priorityRecur(root->left, depth, d, l + 1);
    priorityRecur(root->right, depth, d, l + 1);
}

void InorderPrio(TreeNode* root) {
    if (root == nullptr)
        return;
    InorderPrio(root->left);
    cout << "Node is " << root->val << " Priority is " << root->pri << endl;
    InorderPrio(root->right);
}

int depthOfTree(TreeNode*root) {
    if (root == nullptr)
        return 0;

    int lh = depthOfTree(root->left) + 1;
    int rh = depthOfTree(root->right) + 1;

    return (lh > rh ? lh : rh);
}

TreeNode* AllocNode(int x) {
    return new TreeNode(x);
}
void InsertNode(TreeNode*& root, int x) {
    if (root == nullptr) {
        root = AllocNode(x);
        return;
    }

    // Check where to insert node
    if (x < root->val) {
        InsertNode(root->left, x);
    }
    else {
        InsertNode(root->right, x);
    }

}
void InOrderTree(TreeNode* root) {
    if (root == nullptr)
        return;
    InOrderTree(root->left);
    cout << "Node is " << root->val << endl;
    InOrderTree(root->right);
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
