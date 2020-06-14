// MergeLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    int val;
    Node* next;
    Node(int x) :val(x), next(nullptr) {}
}Node;

void ReverseList(Node*& head);
void PrintList(Node* head);
Node* RecurReverse(Node* curr);

int main()
{
    Node* l1 = nullptr, * l2 = nullptr;
    Node* t1 = nullptr, * t2 = nullptr;

    for (int i = 0; i < 40; i++) {
        if (i % 2 == 0) {
            if (l1 == nullptr) {
                l1 = new Node(rand() % 101);
                t1 = l1;
            }
            else {
                t1->next = new Node(rand() % 101);
                t1 = t1->next;
            }
        }
        else {
            if (l2 == nullptr) {
                l2 = new Node(rand() % 101);
                t2 = l2;
            }
            else {
                t2->next = new Node(rand() % 101);
                t2 = t2->next;
            }

        }
    }

    t1 = l1;
    t2 = l2;
    PrintList(l1);
    cout << endl;
    PrintList(l2);
  
    cout << endl;

    ReverseList(l1);
    PrintList(l1);

    l1 = RecurReverse(l1);
    cout << endl;
    PrintList(l1);
}

void PrintList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* RecurReverse(Node* curr) {
    // Base case
    if (curr == nullptr || curr->next == nullptr)
        return curr;
  
    // Reverse a single node
    Node* temp = RecurReverse(curr->next);
    curr->next->next = curr;

    curr->next = nullptr;
    return temp;
}

void ReverseList(Node*& head) {
    
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
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
