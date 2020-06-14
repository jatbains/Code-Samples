// ConstructStringFromBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
}TreeNode;

using namespace std;

void tree2strpar(TreeNode* root, string& vals);


int main()
{
    std::cout << "Hello World!\n";
}


string tree2str(TreeNode* t) {
    string nodes;
    tree2strpar(t, nodes);
    return nodes;
}

void tree2strpar(TreeNode* root, string& vals) {
    if (root == NULL) {

        return;
    }
    // Preorder
    if (root->left == NULL && root->right == NULL) {


        vals += to_string(root->val);
        return;
    }
    // Check for left and right NULL
    if (root->right == NULL) {

        vals += to_string(root->val);
        vals.push_back('(');
        tree2strpar(root->left, vals);
        vals.push_back(')');
        return;
    }

    vals += to_string(root->val);
    vals.push_back('(');
    tree2strpar(root->left, vals);
    vals += (")(");
    tree2strpar(root->right, vals);
    vals.push_back(')');
    return;
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
