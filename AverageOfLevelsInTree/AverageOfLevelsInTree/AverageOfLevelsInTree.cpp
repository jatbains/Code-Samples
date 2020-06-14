// AverageOfLevelsInTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector<double> averageOfLevels(TreeNode* root) {
    // Find the depth 
    // Go through the tree level by level and find averages
    // Add them to a vector
    int height = DepthOfTree(root);
    vector<int> average;
    double sum = 0.0;
    int count = 0;
    vector<double> result;
    for (int i = 0; i < height; i++)
    {
        Averages(root, 0, i, average);
        // Average out Avergaes! :-)
        for (int i : average)
        {
            sum += i;
            count++;
        }

        result.push_back(sum / count);
        average.clear();
        count = 0;
        sum = 0;
    }
    return result;

}
int DepthOfTree(TreeNode* root)
{
    if (root == NULL)
        return 0;

    int lh = DepthOfTree(root->left) + 1;
    int rh = DepthOfTree(root->right) + 1;

    return (lh > rh ? lh : rh);
}

void Averages(TreeNode* root, int level, int target, vector<int>& average)
{
    if (root == NULL)
        return;
    if (level == target)
    {
        cout << root->val << endl;
        average.push_back(root->val);

    }

    // Left ad right
    Averages(root->left, level + 1, target, average);
    Averages(root->right, level + 1, target, average);
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
