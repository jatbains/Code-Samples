// ValidateBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
}Node;

void InOrder(TreeNode* root,vector<int>& vals);
void InsertNode(TreeNode*& root, int x);
bool IsBST(TreeNode* root);
bool isBSTBin(TreeNode* root, TreeNode* l = NULL, TreeNode* r = NULL);
int DepthOfTree(TreeNode* root);
bool ProveBalancedBST(TreeNode* root);
void BoundaryTraversal(TreeNode* root, vector<int>& vals);
void TraverseLeft(TreeNode* root, vector<int>& vals);
void TraverseRight(TreeNode* root, vector<int>& vals);
void GetLeafNodes(TreeNode* root, vector<int>& vals);
void GreaterSumTree(TreeNode* root, int& sum);
void PrintOrder(TreeNode* root);
int Tilt(TreeNode* root, int& tilt);
int SubTreeSum(TreeNode* root, vector<int>& sums);
bool isSiblings(TreeNode* root, int x, int y);
int NodeLevel(TreeNode* root, int x, int l);

int main()
{
    TreeNode* root = nullptr;
    for (int i = 0; i < 23; i++) {
        InsertNode(root, rand() % 101);
    }
    vector<int> vals;

    InOrder(root,vals);
    cout << endl;
    cout << (isBSTBin(root,NULL,NULL) == true ? "True" : "False" )<< endl;
    for (int i = 1; i < vals.size(); i++) {
        if (vals[i] < vals[i - 1])
            cout << "Not a BST" << endl;
    }

    cout << (ProveBalancedBST(root) == true ? "True" : "False") << endl;

    int sum = 0;
    GreaterSumTree(root, sum);

    PrintOrder(root);
    cout << endl;
   
    vector<int> vals2;
    // Boundary traversal
    TreeNode* root2 = new TreeNode(20);
    root2->left = new TreeNode(8);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(12);
    root2->left->right->left = new TreeNode(10);
    root2->left->right->right = new TreeNode(14);
    root2->right = new TreeNode(22);
    root2->right->right = new TreeNode(25);

    
    BoundaryTraversal(root2, vals2);
    for (int i : vals2) {
        cout << " " << i;
    }

    int tilt = 0;
    Tilt(root, tilt);
    cout << endl<<  "Tilt is " << tilt << endl;
}

bool isSiblings(TreeNode* root, int x, int y) {
    if (root == nullptr)
        return false;
    
    bool areSiblings = false;
    if ((root->left != nullptr) && (root->right != nullptr)) {
        if ((root->left->val == x && root->right->val == y) ||
            (root->left->val == y && root->right->val == x))
            areSiblings = true;
    }

    return ((areSiblings) ||
        isSiblings(root->left, x, y) || isSiblings(root->right, x, y));
}

int NodeLevel(TreeNode* root, int x, int l) {
    if (root == nullptr)
        return 0;
    if (root->val == x)
        return l;      // At this level
    // Recur down the tree
    int ls = NodeLevel(root->left, x, l + 1);
    if (ls != 0)  // found in left subtree
        return ls;
    // try right subtree
    return NodeLevel(root->right, x, l + 1);
}

bool isCousins(TreeNode* root, int x, int y) {
    // Both must be at same level and not siblings
    return ((NodeLevel(root, x, 1) == NodeLevel(root, y, 1)) && !isSiblings(root, x, y));
}

int SubTreeSum(TreeNode* root, vector<int>& sums) {
    if (root == NULL)
        return 0;


    int curSum = root->val + SubTreeSum(root->left, sums) + SubTreeSum(root->right, sums);

    sums.push_back(curSum);

    return curSum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> sums;

    unordered_map<int, int> freq;
    int max_count = 0;
    // Need to find the sum of all subtrees and add them to a vector
    SubTreeSum(root, freq, max_count);


    // Find most common sum
    for (auto i : freq) {
        if (i.second == max_count)
            sums.push_back(i.first);
    }

    // Get the max count


    return sums;
}

int SubTreeSum(TreeNode* root, unordered_map<int, int>& freq, int& max_count) {
    if (root == NULL)
        return 0;

    int curSum = root->val + SubTreeSum(root->left, freq, max_count) + SubTreeSum(root->right, freq, max_count);

    freq[curSum]++;
    max_count = max(max_count, freq[curSum]);

    return curSum;

}

int Tilt(TreeNode* root, int& tilt) {

    if (root == NULL)
        return 0;

    int lt = Tilt(root->left, tilt);

    int rt = Tilt(root->right, tilt);

    tilt += abs(lt - rt);

    return lt + rt + root->val;

}

void PrintOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    PrintOrder(root->left);
    cout << " " << root->val;
    PrintOrder(root->right);
}

void GreaterSumTree(TreeNode* root, int& sum) {
    if (root == NULL)
        return;

    // Reverse In order
    GreaterSumTree(root->right, sum);
    sum = sum + root->val;
    // put in node
    root->val = sum;

    GreaterSumTree(root->left, sum);
}

void TraverseLeft(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;

    if (root->left) {
        // Push back the vals
        vals.push_back(root->val);
        // Check recursively
        TraverseLeft(root->left, vals);
    }
    else if (root->right) {
        vals.push_back(root->val);
        TraverseLeft(root->right, vals);
    }
}

void TraverseRight(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;

    if (root->right) {
        // Push back the vals
        vals.push_back(root->val);
        // Check recursively
        TraverseLeft(root->right, vals);
    }
    else if (root->left) {
        vals.push_back(root->val);
        TraverseLeft(root->left, vals);
    }
}

void GetLeafNodes(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;

    GetLeafNodes(root->left, vals);
    if (root->left == nullptr && root->right == nullptr)
        vals.push_back(root->val);
    GetLeafNodes(root->right, vals);
}

void BoundaryTraversal(TreeNode* root, vector<int>& vals) {
    // Add root
    if (root == nullptr)
        return;
    vals.push_back(root->val);

    // Traverse Left first
    TraverseLeft(root->left, vals);
    // Print Leaf Nodes
    GetLeafNodes(root->left, vals);
    GetLeafNodes(root->right, vals);
    // Traverse Right next
    TraverseRight(root->right, vals);
}

bool ProveBalancedBST(TreeNode* root) {
    // difference between lh and rh is 1 max
    if (root == nullptr)
        return true;

    int lh = DepthOfTree(root->left);
    cout << lh << endl;
 
    int rh = DepthOfTree(root->right);
    cout << rh << endl;

    if (abs(lh - rh) <= 1 && ProveBalancedBST(root->left) && ProveBalancedBST(root->right))
        return true;

    return false;

}

int DepthOfTree(TreeNode* root) {
    if (root == nullptr)
        return 1;  // root
    int lh = DepthOfTree(root->left) + 1;
    int rh = DepthOfTree(root->right) + 1;

    return (lh > rh ? lh : rh);
}

bool isBSTBin(TreeNode* root, TreeNode* l, TreeNode* r )
{
    // Base condition 
    if (root == NULL)
        return true;

    // if left node exist then check it has 
    // correct data or not i.e. left node's data 
    // should be less than root's data 
    if (l != NULL && root->val < l->val)
        return false;

    // if right node exist then check it has 
    // correct data or not i.e. right node's data 
    // should be greater than root's data 
    if (r != NULL && root->val > r->val)
        return false;

    // check recursively for every node. 
    // left then right 
    return isBSTBin(root->left, l, root) &&
        isBSTBin(root->right, root, r);
}

bool IsBST(TreeNode* root) {
    if (root == nullptr)
        return true;

    if (root->left != nullptr) {
        if (root->val < root->left->val)
            return false;
    }
    if (root->right != nullptr) {
        if (root->val > root->right->val)
            return false;
    }
    // Recurse left and right
    return (!IsBST(root->left) || !IsBST(root->right));

    // If is passes the above return true;
    return true;
}

void InOrder(TreeNode* root,vector<int>& vals) {
    if (root == nullptr)
        return;
    InOrder(root->left,vals);
    cout << "Node " << root->val << " ";
    vals.push_back(root->val);
    InOrder(root->right,vals);
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
