// ValidateParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    char p;
    Node* next;
}Node;

Node* InsertNode(Node* head, char p);
char Pop(Node*& head);

bool isValid(string s) 
{
    // Use a stack
    int len = s.length();
    char v;
    bool valid = false;
    Node* head = NULL;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            head = InsertNode(head, s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            v = Pop(head);
            if (s[i] == ')' && v != '(')
            {
                return false;
            }
            else if (s[i] == '}' && v != '{')
            {
                return false;
            }
            else if (s[i] == ']' && v != '[')
            {
                return false;
            }
        }
    }
    // if stack is not empty return false
    if (head != NULL)
        return false;
    return true;
}
Node* InsertNode(Node* head, char p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->p = p;
    temp->next = head;
    head = temp;
    return head;
}
char Pop(Node*& head)
{
    if (head == NULL)
        return 0;
    if (head->next == NULL)
    {
        char v = head->p;
        free(head);
        head = NULL;
        return v;

    }
    Node* temp = head;
    head = head->next;
    char v = temp->p;
    free(temp);
    return v;
}
int main()
{
    string s = "[";

    cout << "Is a valid string " << (isValid(s) ? "True" : "False") << endl;

    // std::cout << "Hello World!\n";
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
