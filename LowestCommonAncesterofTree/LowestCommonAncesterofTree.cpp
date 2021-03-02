// LowestCommonAncesterofTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#if 0
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; left = right = nullptr; }
};
#endif

class TreeNode {
private:
    int val;
    TreeNode* left,*right;

public:
    TreeNode(void);
    TreeNode(int x);
    TreeNode* InsertNode(TreeNode *root,int x);
    void Inorder(TreeNode *root);
};

TreeNode::TreeNode(void) {
    val = 0;
    left = right = nullptr;
}
TreeNode::TreeNode(int x) {
    val = x;
    left = right = nullptr;
}

TreeNode* TreeNode::InsertNode(TreeNode *root,int x) {
    if (root == nullptr) {
        root = new TreeNode(x);
        return root;
    }

    if (x < root->val) {
        root->left = InsertNode(root->left, x);
    }
    else {
        root->right = InsertNode(root->right, x);
    }
    return root;
}

void TreeNode::Inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // left
    Inorder(root->left);
    cout << root->val << " " << endl;
    Inorder(root->right);
    return;
}

int main()
{
    TreeNode* root = nullptr;       // Root pointer
    TreeNode bst;               // Local class instance
    
    for (int i = 0; i < 20; i++) {
        root = bst.InsertNode(root, rand() % 101);
    }
    bst.Inorder(root);
    
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
