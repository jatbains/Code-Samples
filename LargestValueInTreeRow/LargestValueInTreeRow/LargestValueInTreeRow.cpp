// LargestValueInTreeRow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
}TreeNode;
void InOrder(TreeNode* root);
void InsertNode(TreeNode*& root, int x);
int DepthOfTree(TreeNode* root);
void BinaryBalTree(TreeNode*& root, vector<int>& nums, int left, int right);
void BFSMaxVals(TreeNode* root, vector<int>& maxVals);

int main()
{
    TreeNode* root = nullptr;
    vector<int> nums;
    for (int i = 0; i < 20; ++i) {
        int x = rand() % 101;
        nums.push_back(x);
        InsertNode(root, x);
    }
    InOrder(root);
    cout << "Depth of Tree " << DepthOfTree(root) << endl;
    cout << endl;
    for (auto i : nums) {
        cout << " " << i;
    }
    // sort the vector
    sort(nums.begin(), nums.end());
    cout << endl;
    for (auto i : nums) {
        cout << " " << i;
    }
    TreeNode* balRoot = nullptr;
    BinaryBalTree(balRoot, nums, 0, nums.size() - 1);
    cout << endl;
    cout << "Depth of Tree " << DepthOfTree(balRoot) << endl;
    InOrder(balRoot);
    vector<int> maxVals;
    BFSMaxVals(balRoot, maxVals);
    int level = 1;
    for (int i : maxVals) {
        cout << "Level " << level << " Val " << i << endl;
        level++;
    }
}

void BFSMaxVals(TreeNode* root,vector<int>& maxVals) {
    int curMax = INT_MIN;
    int count = 0;
    
    queue<TreeNode*> tQueue;
    // push in the root
    tQueue.push(root);
    // Do processing until queue empth
    while (!tQueue.empty()) {
        count = tQueue.size();
        while (count) {
            // pull from front of queue
            // update curMax if val > curMax
            TreeNode* front = tQueue.front();
            tQueue.pop();
            if (front->val > curMax)
                curMax = front->val;
            // Push in the left and right
            if (front->left != nullptr) {
                tQueue.push(front->left);
            }
            if (front->right != nullptr) {
                tQueue.push(front->right);
            }
            count--;
        }
        // Push back the curMax
        maxVals.push_back(curMax);
        curMax = INT_MIN;
    }
    
}

void BinaryBalTree(TreeNode*& root, vector<int>& nums, int left, int right) {
    // Base condition
    if (left > right)
        return;
    int mid = left + (right - left) / 2;
    root = new TreeNode(nums[mid]);
    // Insert Left
    BinaryBalTree(root->left, nums, left, mid - 1);
    BinaryBalTree(root->right, nums, mid + 1, right);
}

int DepthOfTree(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int lh = 1 + DepthOfTree(root->left);
    int rh = 1 + DepthOfTree(root->right);
    return (lh > rh ? lh : rh);
}
void InsertNode(TreeNode*& root, int x) {
    if (root == nullptr) {
        root = new TreeNode(x);
        return;
    }
    if (x < root->val) {
        InsertNode(root->left, x);
    }
    else {
        InsertNode(root->right, x);
    }
}

void InOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    InOrder(root->left);
    cout << " Val " << root->val << endl;
    InOrder(root->right);
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
