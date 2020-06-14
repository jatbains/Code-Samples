// MergeTwoBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
}TreeNode;

using namespace std;


int main()
{
    std::cout << "Hello World!\n";
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    // DO a Inorder search for both and compare values
    vector<int> out1;
    vector<int> out2;
    vector<int> result;
    // Get in order from both trees and merge the result
   // GetValsSorted(root1,root2,out);
    GetInOrder(root1, out1);
    GetInOrder(root2, out2);

    int i = 0, j = 0;
    while (i < out1.size() && j < out2.size())
    {
        if (out1[i] < out2[j])
        {
            result.push_back(out1[i]);
            i++;
        }
        else {
            result.push_back(out2[j]);
            j++;
        }

    }
    while (i < out1.size())
    {
        result.push_back(out1[i]);
        i++;
    }
    while (j < out2.size())
    {
        result.push_back(out2[j]);
        j++;
    }

    return result;

}
void GetInOrder(TreeNode* root, vector<int>& vals)
{
    if (root == NULL)
        return;
    GetInOrder(root->left, vals);
    vals.push_back(root->val);
    GetInOrder(root->right, vals);
}


void GetValsSorted(TreeNode* r1, TreeNode* r2, vector<int>& out)
{
    if (r1 == NULL && r2 == NULL)
        return;


    if (r1->val < r2->val)
    {
        out.push_back(r1->val);
        GetValsSorted(r1->left, r2, out);
    }
    if (r1 == NULL)
        out.push_back(r2->val);
    if (r2 == NULL)
        out.push_back(r1->val);
    if (r2->val < r1->val)
    {
        out.push_back(r2->val);
        GetValsSorted(r1->right, r2->left, out);
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
