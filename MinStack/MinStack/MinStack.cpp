// MinStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


typedef struct Node {
    int val;
    int min;
    Node* next;
}Node;

using namespace std;

class MinStack
{
private:
    int min;
    Node* head;

public:
    
    MinStack() {
        head = NULL;
        min = INT_MAX;
    }
    void Push(int val);
    int Top(void);
    void Pop();
    int getMin(void);
    Node* AllocNode(int x);
};

int MinStack::Top(void)
{
    if (head == NULL)
        return 0;
    else {
        return head->val;
    }
}

Node* MinStack::AllocNode(int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = x;
    temp->next = NULL;
    return temp;
}

void MinStack::Pop(void)
{
    if (head == NULL)
        return;
    // if removing min update next

    int val = head->val;

    Node* temp = head;
    head = head->next;
    if (val < min)   // Removing min
    {
        if (head != NULL)
            min = head->min;
        else
            min = INT_MAX;
    }


    free(temp);
}

void MinStack::Push(int x)
{
    // Update min
    if (min > x)
        min = x;
    Node* temp = AllocNode(x);
    temp->min = min;
    if (head == NULL)
        head = temp;
    else {
        temp->next = head;
        head = temp;
    }
}

int MinStack::getMin(void)
{
    return head->min;
}

int main()
{
    MinStack minS;

    minS.Push(-2);
    minS.Push(0);
    minS.Push(-3);

    cout << minS.getMin() << endl;
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
