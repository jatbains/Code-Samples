// BinTreePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> binaryTreePaths(TreeNode* root);
void binTreeRecur(TreeNode* root, vector<string>& paths, vector<int>& nodes, int path_len);
TreeNode* AllocNode(int val);
void InsertNode(TreeNode*& root, int val);
void PrintInOrder(TreeNode* root);
int Depth(TreeNode* root);

int main()
{
    TreeNode* root = nullptr;
    vector<string> paths;
    

    InsertNode(root, 2);
    InsertNode(root, 1);
    InsertNode(root, 3);
    InsertNode(root, 5);

    PrintInOrder(root);
    
    cout << "Height " << Depth(root);
    cout << "Paths Are" << endl;
    paths = binaryTreePaths(root);


    for (string s : paths)
    {
        cout << s << endl;
    }
    //std::cout << "Hello World!\n";
}

int Depth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    int lh = 1 + Depth(root->left);
    int rh = 1 + Depth(root->right);

    return (lh > rh ? lh : rh);
}

void PrintInOrder(TreeNode* root)
{
    if (root == nullptr)
        return;

    PrintInOrder(root->left);
    cout << " " << root->val << " " << endl;
    PrintInOrder(root->right);
}

TreeNode* AllocNode(int val)
{
    TreeNode* temp = new TreeNode(val);
    return temp;
}

void InsertNode(TreeNode*& root, int val)
{
    if (root == nullptr)
    {
        root = AllocNode(val);
    }
    else
    {
        if (val < root->val)
        {
            InsertNode(root->left, val);
        }
        else
        {
            InsertNode(root->right, val);
        }
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    int depth = Depth(root);
    vector<int> nodes;
    nodes.resize(depth+1);
    binTreeRecur(root, paths, nodes, 0);
    return paths;
}
void binTreeRecur(TreeNode* root, vector<string>& paths, vector<int>& nodes, int path_len)
{

    if (root == NULL)
        return;       // bottom
    // Add node to list

    nodes[path_len] = root->val;
    cout << path_len << endl;
    path_len++;
    
    if (root->left == NULL && root->right == NULL)
    {
        string p;
        // leaf node
        int i;
        for (i = 0; i < path_len-1; i++) {
            string s = to_string(nodes[i]);
            p += s + "->";

        }
        // Add last
        string s = to_string(nodes[i]);
        p += s;
        paths.push_back(p);

    }
    else
    {
        binTreeRecur(root->left, paths, nodes, path_len);
        binTreeRecur(root->right, paths, nodes, path_len);
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
