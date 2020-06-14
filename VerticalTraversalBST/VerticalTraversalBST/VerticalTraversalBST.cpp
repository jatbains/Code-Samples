// VerticalTraversalBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}TreeNode;

// Modify algorithm to add depth and vertical distance
void PrintInOrder(TreeNode* root);
TreeNode* AllocNode(int x);
void InsertInTree(TreeNode*& root, int x);
void printVerticalOrder(TreeNode* root, vector<vector<int>>& cols);
void GetCol(TreeNode* root, int col, int hd, int depth, vector<pair<int, int>>& vcol);
void findminmax(TreeNode* root, int& min, int& max, int hd);
int findDepth(TreeNode* root);
vector<vector<int>> verticalTraversal(TreeNode* root);

int main()
{
    TreeNode* root = nullptr;
    vector<vector<int>> vert;

    for (int i = 0; i <= 20; i++) {
        InsertInTree(root, rand() % 100);
    }

    PrintInOrder(root);
    cout << endl;
    cout << "Height is " << findDepth(root) << endl;

    // Vertical Traversal
    cout << endl;
   vert = verticalTraversal(root);
   for (vector<int> v : vert) {
       for (int i : v) {
           cout << "Node " << i << " ";
       }
       cout << endl;
   }
}

int findDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int lh = findDepth(root->left) + 1;
    int rh = findDepth(root->right) + 1;

    return (lh > rh ? lh : rh);
}

void PrintInOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    PrintInOrder(root->left);
    cout << root->val << " ";
    PrintInOrder(root->right);
}

TreeNode* AllocNode(int x) {
    TreeNode* temp = new TreeNode(x);
    return temp;
}

void InsertInTree(TreeNode*& root, int x) {
    // First base case
    if (root == nullptr) {
        // Insert node here
        root = AllocNode(x);
        return;
    }
    // Search where to insert node
    if (x < root->val) {   // Less than val go left
        InsertInTree(root->left, x);
    }
    else {                 // Greater than val go right
        InsertInTree(root->right, x);
    }
}

void printVerticalOrder(TreeNode* root, vector<vector<int>>& cols) {
    // Base case 
    if (!root)
        return;
    vector<int> col;
    // Create a map and store vertical oder in 
    // map using function getVerticalOrder() 
    map < int, vector<int> > m;
    int hd = 0;

    // Create queue to do level order traversal. 
    // Every item of queue contains node and 
    // horizontal distance. 
    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(root, hd));

    while (!que.empty())
    {
        // pop from queue front 
        pair<TreeNode*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* node = temp.first;

        // insert this node's data in vector of hash 
        m[hd].push_back(node->val);

        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }

    // Traverse the map and print nodes at 
    // every horigontal distance (hd) 
    map< int, vector<int> > ::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i) {
            cout << it->second[i] << " ";
            col.push_back(it->second[i]);
        }
        cols.push_back(col);
        col.clear();
    }
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> cols;
    // Find the min and max displacement from the root
    int min = 0, max = 0;
    findminmax(root, min, max, 0);
    cout << "Min " << min << " Max " << max << endl;

    vector<pair<int,int>> col;

    for (int i = min; i <= max; i++) {

        GetCol(root, i, 0, 0, col);
       
        // it->first[i] is the column number for node 
        // it->second[i] is the depth of the node  
        // Sort on the depth of the nodes the pair
        sort(col.begin(), col.end());
 
        vector<int> ans;
        for (auto i : col) {
            ans.push_back(i.second);      // first is the value of node
        }
        // Sort the vector of pair so that elements with same horizontal and vertical levels are corrected
        //sort(row_vec.begin(), row_vec.end());
        // Check for depth in the pair
        cols.push_back(ans);
        ans.clear();
        col.clear();
    }

    return cols;
}
void GetCol(TreeNode* root, int col, int hd,int depth, vector<pair<int,int>>& vcol) {
    if (root == NULL)
        return;
    if (col == hd) {
       // vcol.push_back(make_pair(root->val,depth));
        vcol.push_back(make_pair(depth, root->val));
    }
   
    GetCol(root->left, col, hd - 1, depth + 1, vcol);
    GetCol(root->right, col, hd + 1, depth + 1, vcol);
}

void findminmax(TreeNode* root, int& min, int& max, int hd) {
    if (root == NULL)
        return;

    if (min > hd)
        min = hd;
    else if (max < hd)
        max = hd;
    // Go to left and right subtrees
    findminmax(root->left, min, max, hd - 1);
    findminmax(root->right, min, max, hd + 1);
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
