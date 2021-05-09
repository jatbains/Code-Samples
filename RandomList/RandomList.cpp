// RandomList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

typedef struct Node {
    int val;
    Node* next;
    Node* rnd;
    Node(int x) :val(x), next(nullptr), rnd(nullptr) {}
}Node;

Node* CopyList(Node* head);
Node* CopyInPlace(Node* head);

int main()
{
    std::cout << "Hello World!\n";
}

Node* CopyList(Node* head) {
    // Check for empty list
    if (head == nullptr)
        return nullptr;

    Node* t1 = nullptr;
    Node* t2 = nullptr;
    map<Node*, Node*> rndMap;
    // Copy first element
    Node* cList = new Node(head->val);

    t2 = cList->next;
    // Copy remaining elements 
    t1 = head->next;
    while (t1 != nullptr) {
        Node* temp = new Node(t1->val);
        t2 = temp;
        t2->val = t1->val;
        // Move pointers forward
        t1 = t1->next;
        t2 = t2->next;
    }
    // Copy all Random pointers
    t1 = head;
    t2 = cList;
    while (t1 != nullptr) {
        rndMap[t1->rnd] = t2;
        t1 = t1->next;
        t2 = t2->next;
    }

    return cList;
}

Node* CopyInPlace(Node* orig) {
    Node* curr = orig, * temp = nullptr;

    // Create a new list and copy random pointers after
    if (orig == nullptr)
        return nullptr;

    while (curr != nullptr) {
        temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr = temp;
    }
 
    curr = orig; // Start at beginning
    // Copy Random Pointers
    while (curr) {
        if (curr->next) {
            curr->next->rnd = curr->rnd ? curr->rnd->next : curr->rnd;

        }
        // move to next node
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node* copy = orig->next;
    Node* start = orig;
    temp = copy;

    while (start && copy) {
        start->next = start->next ? start->next->next : start->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        start = start->next;
        copy = copy->next;
    }

    return temp;
}

void PrintList(Node* head) {
    while(head != nullptr) {
        cout << "Val is " << head->val << endl;
        head = head->next;
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
