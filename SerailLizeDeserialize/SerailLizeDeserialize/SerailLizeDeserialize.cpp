// SerailLizeDeserialize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
    int val;
    Node* left, * right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
}Node;

void PrintInOrder(Node* root);
Node* Alloc(int x);
void InsertNode(Node*& root, int x);
void Serialize(Node* root, vector<int>& list);
void Deserialize(Node*& root, vector<int>& list);

int main()
{
    Node* root = nullptr;
    // Create a tree
    for (int i = 0; i < 20; i++) {
        InsertNode(root, rand() % 101);
    }

    PrintInOrder(root);
    vector<int> nodes;
    Serialize(root, nodes);
    for (int i : nodes) {
        cout << i << " ";
    }

    vector<int> list;
    Serialize(root, list);
    cout << endl;
    for (int i : list) {
        cout << i << " ";
    }
    Node* newRoot;
    Deserialize(newRoot , list);
    cout << endl;
    PrintInOrder(newRoot);
    //std::cout << "Hello World!\n";
}

void Deserialize(Node*& root, vector<int>& list) {
    if (list.front() == -1 || list.empty()) {
        root = nullptr;
        list.erase(list.begin(),list.begin()+1);
        return;
    }
    root = Alloc(list.front());
    list.erase(list.begin(),list.begin()+1);
    Deserialize(root->left, list);
    Deserialize(root->right, list);

}

void Serialize(Node* root, vector<int>& list) {
    if (root == nullptr) {
        list.push_back(-1);
        return;
    }
    list.push_back(root->val);
    // Left and right
    Serialize(root->left, list);
    // root
  
    Serialize(root->right, list);
}

void PrintInOrder(Node* root) {
    if (root == nullptr)
        return;
    PrintInOrder(root->left);
    cout << "Node Val " << root->val << endl;
    PrintInOrder(root->right);
}

Node* Alloc(int x) {
    Node* temp = new Node(x);
    return temp;
}

void InsertNode(Node*& root, int x) {
    if (root == nullptr) {
        root = Alloc(x);
        return;
    }
    // Insert either left or right
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
