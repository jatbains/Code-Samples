// LinkedListRandomNode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x),next(nullptr) {}
}ListNode;

void InsertNode(ListNode*& head, int x);
int getRandom(ListNode* head, int size);

using namespace std;

int main()
{
    ListNode* head = nullptr;

    for (int i = 0; i < 20; i++) {
        InsertNode(head, rand() % 57);
    }
    int count = 20;
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
       
    cout << endl;
    int rand = getRandom(head, count);
    cout << "Random Value is " << rand;
}

int getRandom(ListNode* head, int size) {
    // find random node

    int rnode = rand() % (size+1);  // find rnode
    cout << endl << "Random Node " << rnode << endl;
    int val = 0;
    ListNode* cur = head;
    int count = 1;
    while (cur != NULL) {
        if (count == rnode) {
            val = cur->val;
            break;
        }
        count++;
        cur = cur->next;
    }
    return val;
}

void InsertNode(ListNode*& head,int x) {
    if (head == nullptr) {
        head = new ListNode(x);
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(x);
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
