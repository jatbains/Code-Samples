// BinaryTreeLevelUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef struct Tree {
    int val;
    Tree* left, * right;
    Tree(int x) :val(x), left(nullptr), right(nullptr) {}
}Tree;

void insertNode(Tree*& root, int x);
void inOrder(Tree* root);
int Depth(Tree* root);


using namespace std;

void PrintLevelUp(Tree* root, int level, int target, vector<int>& vlevel);
void PrintTopDown(Tree* root, int level, int target, vector<int>& vlevel);

int main()
{
    Tree* root = nullptr;
    int depth = 0;

    for (int i = 0; i < 20; ++i) {
        insertNode(root, rand() % 51);
    }
    inOrder(root);
    depth = Depth(root);
    cout << "Depth of Tree " << depth << endl;
    vector<vector<int>> levels;
    vector<int> level;
    // Print leaf up
    cout << endl << endl;
    for (int i = 1; i <= depth; i++) {
        cout << "Level " << i << endl;
        PrintLevelUp(root, i, depth, level);
        levels.push_back(level);
        level.clear();
        cout << endl;
    }

    cout << endl << endl;
    int i = depth;
    for (vector<int> v : levels) {
        cout << " Level " << i << endl;
        for (int i : v) {
            cout << " Val " << i;
        }
        i--;
        cout << endl;
    }
    levels.clear();

    for (int i = 1; i <= depth; i++) {
        cout << "Level " << i << endl;
        PrintTopDown(root, 1, i, level);
        levels.push_back(level);
        level.clear();
        cout << endl;
    }

    cout << endl << endl;
    i = depth;
    for (vector<int> v : levels) {
        cout << " Level " << i << endl;
        for (int i : v) {
            cout << " Val " << i;
        }
        i--;
        cout << endl;
    }
}

void PrintTopDown(Tree* root, int level, int target, vector<int>& vlevel) {
    if (root == nullptr)
        return;
    if (level == target)
        vlevel.push_back(root->val);

    PrintTopDown(root->left, level + 1, target, vlevel);
    PrintTopDown(root->right, level + 1, target, vlevel);
}

void PrintLevelUp(Tree* root, int level, int target, vector<int>& vlevel) {
    if (root == nullptr)
        return;
    if (level == target) {
        cout << " Val " << root->val;
        vlevel.push_back(root->val);
    }
    // Search left and right subtrees
    PrintLevelUp(root->left, level + 1, target, vlevel);
    PrintLevelUp(root->right, level + 1, target, vlevel);
}

int Depth(Tree* root) {
    if (root == nullptr)
        return 0;
    int lh = 1 + Depth(root->left);
    int rh = 1 + Depth(root->right);
    return (lh > rh ? lh : rh);
}

void inOrder(Tree* root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << "Val " << root->val << endl;
    inOrder(root->right);
}

void insertNode(Tree*& root, int x) {
    if (root == nullptr) {
        root = new Tree(x);
        return;
    }
    // Insert Left or right
    if (x < root->val) {
        insertNode(root->left, x);
    }
    else {
        insertNode(root->right, x);
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
