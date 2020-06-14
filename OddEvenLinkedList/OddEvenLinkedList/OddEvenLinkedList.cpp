// OddEvenLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
}ListNode;



int main()
{
    // Create a Linked List
    ListNode* head = new ListNode(23);

    ListNode* temp = head;
    for (int i = 0; i < 10; i++) {
        temp->next = new ListNode(rand() % 51);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr) {
        cout << "Val " << temp->val << endl;
        temp = temp->next;
    }

    //std::cout << "Hello World!\n";
}

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd, * even;
    odd = head;
    ListNode* newHead = head;
    ListNode* evenHead;
    if (head == NULL)
        return odd;
    if (head->next == NULL)
        return odd;
    even = head->next;
    evenHead = even;
    // create two list odd and even and link at end

    while (odd->next != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        // Move forward pointers
        even = even->next;
    }

    odd->next = evenHead;
    return newHead;
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
