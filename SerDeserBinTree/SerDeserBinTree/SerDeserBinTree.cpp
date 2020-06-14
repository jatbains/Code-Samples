// SerDeserBinTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}TreeNode;

void BinTree(TreeNode*& root, vector<int>& nums, int left, int right);
void PrintInOrder(TreeNode* root);
int Depth(TreeNode* root);
void Serialize(TreeNode* root, string& data);
void Deserialize(TreeNode*& root, string& data);

int main()
{
    TreeNode* root = nullptr;
    vector<int> nums;
    string sTree = "";

    for (int i = 0; i < 20; i++) {
        nums.push_back(rand() % 101);
    }
    // sort the vector
    sort(nums.begin(), nums.end());

    // Do binary search to create tree
    BinTree(root, nums, 0, nums.size() - 1);
    PrintInOrder(root);

    cout << "Depth of balanced tree " << Depth(root) << endl;
    Serialize(root, sTree);

    cout << sTree << endl;

    TreeNode* desT = nullptr;
    Deserialize(desT, sTree);

    PrintInOrder(desT);
}

void Serialize(TreeNode* root,string& data) {
    if (root == nullptr) {
        data += "N,";
        return;
    }
    else {
        data += to_string(root->val) + ",";
    }
    
    Serialize(root->left, data);
    Serialize(root->right, data);
}

void Deserialize(TreeNode*& root,string& data) {
    if (data.size() == 0)
        return;

    int pos = data.find(",");
    string s = data.substr(0, pos);
    if (!isdigit(s[0])) {
        data = data.substr(pos + 1);
        return;
    }

    root = new TreeNode(stoi(s));
    
    data = data.substr(pos + 1);
    // Recur
    Deserialize(root->left, data);
    Deserialize(root->right, data);
}

void PrintInOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    PrintInOrder(root->left);
    cout << "Val " << root->val << endl;
    PrintInOrder(root->right);
}

void BinTree(TreeNode*& root,vector<int>&nums, int left, int right) {

    // Base case
    if (left > right)
        return;
    int mid = left + (right - left) / 2;
    root = new TreeNode(nums[mid]);

    // left and right
    BinTree(root->left, nums, left, mid - 1);
    BinTree(root->right, nums, mid + 1, right);

}

int Depth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int lh = 1 + Depth(root->left);
    int rh = 1 + Depth(root->right);
    return(lh > rh ? lh : rh);
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
