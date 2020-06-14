// SplitLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {

    int n = 0;
    vector<ListNode*> res;
    ListNode* cur = root;

    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    // parts will be n/k
    cur = root;
    ListNode* pre = NULL;
    int num = 0;
    res.push_back(root);
    while (cur != NULL) {
        if (num = n / k) {
            pre->next = NULL;
            res.push_back(cur);
        }
        num++;
        pre = cur;
        cur = cur->next;
    }
    return res;
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
