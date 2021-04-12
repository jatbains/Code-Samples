// BSTTreeClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;



typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    
}TreeNode;

class BST {
private:
 
    TreeNode* root;
   
    void ClearTree(TreeNode*& t);
    void InsertNode(TreeNode*& t, int x);
    void InOrder(TreeNode* root);
    void PreOrder(TreeNode* root);
    void PostOrder(TreeNode* root);
    int DepthOfTree(TreeNode* root);
    int SizeOfTree(TreeNode* root);
    bool IsValueInTree(TreeNode* root, int val);
    bool IsTreeBalanced(TreeNode* root);
public:
 
    BST() :root(nullptr) {}
    ~BST() { ClearTree(root); }
    void InsertNode(int x) { InsertNode(root, x); }
    void InOrder() { InOrder(root); }
    int GetVal() { return root->val; }
    int DepthOfTree() { return DepthOfTree(root); }
    void PreOrder() { PreOrder(root); }
    void PostOrder() { PostOrder(root); }
    int SizeOfTree() { return SizeOfTree(root); }
    bool IsValueInTree(int x) { return IsValueInTree(root, x); }
    bool IsTreeBalanced() { return IsTreeBalanced(root); }
};

bool BST::IsTreeBalanced(TreeNode* root) {
    if (root == nullptr)
        return false;

    int lh = 1 + IsTreeBalanced(root->left);
    int rh = 1 + IsTreeBalanced(root->right);
    return (lh == rh);
}

bool BST::IsValueInTree(TreeNode* root, int x) {
    if (root == nullptr)
        return false;
    if (root->val == x)
        return true;
    // Search left and right subtrees
    return IsValueInTree(root->left, x) || IsValueInTree(root->right, x);
}

int BST::DepthOfTree(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int lh = DepthOfTree(root->left);
    int rh = DepthOfTree(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int BST::SizeOfTree(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + SizeOfTree(root->left) + SizeOfTree(root->right);
}

void BST::InsertNode(TreeNode*& root, int x) {
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
void BST::PreOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->val << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}
void BST::PostOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << endl;
}

void BST::InOrder(TreeNode *root) {
    if (root == nullptr)
        return;

    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

void BST::ClearTree(TreeNode*& root) {
    if (root == nullptr)
        return;
    ClearTree(root->left);
    ClearTree(root->right);
    delete root;
    return;
}

void QSort(vector<int>& v, int l, int h);
int partition(vector<int>& v, int l, int h);
void BalancedTree(BST& bst, vector<int>& v);
void InsertBST(BST& bst, vector<int>& v, int l, int h);

int main()
{
    BST bst;
    int val = 0;
    vector<int> vals;
    
    for (int i = 0; i < 20; i++) {
        val = rand() % 101;
        bst.InsertNode(val);
        vals.push_back(val);
    }
    bst.InOrder();
    cout << endl;
    cout << endl << bst.DepthOfTree() << endl;
    for (int i : vals) {
        cout << i << " ";
    }
    // sort vals
    cout << endl;
    QSort(vals, 0, vals.size() - 1);
    for (int i : vals) {
        cout << i << " ";
    }
    // Binary Insert
}

void InsertBST(BST& bst, vector<int>& v, int l, int h) {

    if (l > h)
        return;
    int mid = l + (h - l) / 2;
    bst.InsertNode(v[mid]);
    // Insert left sub tree
    InsertBST(bst, v, l, mid - 1);
    // INsert right subtree
    InsertBST(bst, v, mid + 1, h);
}

void BalancedTree(BST& bst, vector<int>& v) {

    int len = v.size() - 1;

    InsertBST(bst, v, 0, len);

}

int partition(vector<int>&v, int l, int h) {
    int pivot = v[l + (h - l) / 2];

    while (l < h) {
        while (v[l] < pivot)
            l++;
        while (v[h] > pivot)
            h--;
        if (l <= h) {
            int x = v[l];
            v[l] = v[h];
            v[h] = x;
            l++;
            h--;
        }
    }
    return l;
}
// Quicksort
void QSort(vector<int>& v,int l, int h) {
    // find partition point
    int pi = partition(v, l, h);

    if (l < pi - 1) {

        QSort(v, l, pi - 1);
    }
    if (pi < h) {
        QSort(v, pi , h);
    }
}


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
