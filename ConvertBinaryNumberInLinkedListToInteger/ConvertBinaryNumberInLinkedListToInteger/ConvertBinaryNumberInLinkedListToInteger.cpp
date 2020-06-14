// ConvertBinaryNumberInLinkedListToInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x),next(NULL) { }
}ListNode;

ListNode* AllocNode(int x);
ListNode* InsertNode(ListNode* head, int x);
void PrintList(ListNode* head);
ListNode* ReverseList(ListNode* head);
int DecimalValue(ListNode* head);

int main()
{
    ListNode* head = nullptr;
    ListNode* revL = nullptr;
    // Create Binary number
    // [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
    head = InsertNode(head,0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 1);
    head = InsertNode(head, 1);
    head = InsertNode(head, 1);
    head = InsertNode(head, 0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 1);
    head = InsertNode(head, 0);
    head = InsertNode(head, 0);
    head = InsertNode(head, 1);

    cout << "Head is " << DecimalValue(head) << endl;

    PrintList(head);
   // std::cout << "Hello World!\n";
    revL = ReverseList(head);
    PrintList(revL);

    cout << "Reverse is " << DecimalValue(revL) << endl;

}

int DecimalValue(ListNode* head)
{
    int res = 0;
    
    while (head != nullptr)
    {
        res = (res << 1) + head->val;
        head = head->next;
    }
    return res;
}

void PrintList(ListNode* head)
{
    cout << endl;
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* ReverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr)
    {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode* InsertNode(ListNode* head,int x)
{
    if (head == nullptr)
        return AllocNode(x);

    ListNode* temp = AllocNode(x);
    // Insert at head
    temp->next = head;

    head = temp;

    return head;
}


ListNode* AllocNode(int x)
{
    ListNode* temp = new ListNode(x);
    return temp;
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
