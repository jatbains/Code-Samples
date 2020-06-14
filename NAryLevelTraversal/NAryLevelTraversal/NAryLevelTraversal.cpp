// NAryLevelTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

using namespace std;
vector<vector<int>> levelOrder(Node* root);

int main()
{
    Node* root = nullptr;
    vector<vector<int>> nodeLevel;

    nodeLevel = levelOrder(root);
}


vector<vector<int>> levelOrder(Node* root) {

    vector<vector<int>> levels;
    if (root == nullptr)
        return levels;
    vector<int> level;
    // Create a queue
    queue<Node*> lTree;
    // Push in root
    lTree.push(root);
    while (!lTree.empty()) {
        // Get count of nodes at this level
        int count = lTree.size();
        level.clear();
        // Pull out elements while count > 0
        while (count > 0) {
            Node* temp = lTree.front();
            lTree.pop();
            level.push_back(temp->val);
            count--;
            // decrement count of elements

            // push in the children
            for (Node* node : temp->children) {
                lTree.push(node);
            }
        }
        // Push in level
        levels.push_back(level);
 
    }
    return levels;
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
