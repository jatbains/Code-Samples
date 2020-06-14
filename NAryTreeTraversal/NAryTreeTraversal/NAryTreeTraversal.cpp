// NAryTreeTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

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

vector<int> preorder(Node* root);
void PreOrderRecur(Node* root, vector<int>& nAryList);

int main()
{
    std::cout << "Hello World!\n";
}

vector<int> preorder(Node* root) {
    // Preorder :  Root, then through the array in a while loop
    vector<int> AryList;

    PreOrderRecur(root, AryList);
    return AryList;

}

void PreOrderRecur(Node* root, vector<int>& nAryList)
{
    if (root == NULL)
        return;


    // Root not NULL 
    nAryList.push_back(root->val);
    // Traverse from Left to right
    for (Node* node : root->children)
    {
        PreOrderRecur(node, nAryList);
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
