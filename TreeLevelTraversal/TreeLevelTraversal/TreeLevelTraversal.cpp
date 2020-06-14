// TreeLevelTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}TreeNode;

vector<int> rightSideView(TreeNode* root);
void findNodes(TreeNode* root, int d, int l, vector<int>& level);
int depth(TreeNode* root);
TreeNode* allocNode(int x);
void insertNode(TreeNode*& root, int x);
void inOrder(TreeNode* root);
void nodeCount(TreeNode* root, int& count);

int main()
{
    TreeNode* root = nullptr;
    vector<int> rsView;

    cout << "Tree Right side " << endl;

    for (int i = 0; i < 20; i++) {
        insertNode(root, rand() % 101);
    }
    // Print
    inOrder(root);
   
    rsView = rightSideView(root);
    
    for (int i : rsView) {
        cout << " " << i << " ";
    }
    cout << endl;
    int count = 0;
    nodeCount(root, count);
    cout << "Number of Nodes " << count << endl;
}

TreeNode* allocNode(int x) {
    TreeNode* temp = new TreeNode(x);
    return temp;
}

void nodeCount(TreeNode* root, int& count) {
    if (root == nullptr)
        return;
    // increment count
    count++;
    //search left and right subtrees
    nodeCount(root->left, count);
    nodeCount(root->right, count);
}

void insertNode(TreeNode*& root, int x) {
    if (root == nullptr) {
        root = allocNode(x);
        return;
    }
    // Insert left or right
    if (x < root->val) {
        insertNode(root->left, x);
    }
    else {
        insertNode(root->right, x);
    }
}

void inOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << " Node " << root->val << " " << endl;
    inOrder(root->right);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> rs;
    vector<int> level;
    vector<int>::iterator it;
    int dep = depth(root);

    // Recursively go through levels finding nodes at that level
    for (int i = 0; i < dep; i++) {
        findNodes(root, 0, i, level);
        // Grab the last element from level and put it in rs
        if (level.size() != 0) {
            int x = level[level.size() - 1];
            rs.push_back(x);

        }
        level.clear();
    }
    return rs;
}
void findNodes(TreeNode* root, int d, int l, vector<int>& level) {
    if (root == NULL) {
        return;    // empty level
    }
    if (d == l) {
        level.push_back(root->val);
        return;
    }
    // Go left and right
    findNodes(root->left, d + 1, l, level);
    findNodes(root->right, d + 1, l, level);

}

int depth(TreeNode* root) {
    if (root == NULL)
        return 0;

    int lh = depth(root->left) + 1;
    int rh = depth(root->right) + 1;

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
