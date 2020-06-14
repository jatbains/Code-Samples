// MergeSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct Node {
    int val;
    Node* next;
    Node(int x) :val(x), next(nullptr) {}
}Node;

using namespace std;
void PrintList(Node* p);

int main()
{
    // Two lists
    Node *a = nullptr, *b = nullptr;
    Node *t1 = a, *t2 = b;
    // Create two lists
    Node* temp = nullptr;
    temp = new Node(2);
    t1 = temp;
    a = t1;
    temp = new Node(5);
    t1->next = temp;
    t1 = t1->next;
    temp = new Node(7);
    t1->next = temp;
    t1 = t1->next;   // NULL
    // List 2
    temp = new Node(3);
    t2 = temp;
    b = t2;
    temp = new Node(9);
    t2->next = temp;
    t2 = t2->next;
    temp = new Node(13);
    t2->next = temp;
    t2 = t2->next;     // NULL
    
    PrintList(a);
    cout << endl;
    PrintList(b);
    cout << endl;
    t1 = a;
    t2 = b;
    // Merge lists
    Node* tail = nullptr;
    Node dummy(0);

    tail = &dummy;

    while (t1 != NULL && t2 != NULL) {
        if (t1->val < t2->val) {
            tail->next = t1;
            t1 = t1->next;
        }
        else
        {
            tail->next = t2;
            t2 = t2->next;
        }
        tail = tail->next;
    }
    if (t1 != NULL) {
        tail->next = t1;
    }
    if (t2 != NULL) {
        tail->next = t2;
    }
    Node* nhead = dummy.next;
    // print out list
    cout << endl;
    PrintList(nhead);
    cout << endl;
}
void PrintList(Node* p) {
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
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
