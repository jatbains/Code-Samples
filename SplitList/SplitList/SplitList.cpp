// SplitList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

vector<list<int>*> SplitList(list<int>& vals, int k);

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

void InsertNode(ListNode*& head, int val);
vector<ListNode*> SplitList(ListNode* head, const unsigned int k);

int main()
{
    ListNode* head = nullptr;
    list<int> vals;
    for (int i = 1; i <= 10; i++) {
        vals.push_back(i);
        InsertNode(head, i);
    }

    for (int i : vals) {
        cout << " " << i;
    }
    cout << endl;
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << " " << temp->val;
        temp = temp->next;
    }
    cout << endl;
    int k = 3;
    vector<ListNode*> nodeList;
    nodeList = SplitList(head, k);
    cout << endl;
    for (ListNode* p : nodeList) {
        cout << " " << p->val;
    }
}

vector<ListNode*> SplitList(ListNode* root, const unsigned int k) {
    int count = 0;
    ListNode* temp = root;
    vector<ListNode*> nodes{ k };
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    int size = 0;
    int rem = 0;
    // if count < k  then split into 1,1,1, until count and null for k-count
    // else if count%k == 0  then equal size 
    // else add one count-1%k    7 % 5=2  max n-1 extra
    if (count < k)
        size = 1;
    else {
        rem = count % k;
        size = count / k;
    }

    ListNode* cur = root;
    ListNode* write = nullptr;
    for (int i = 0; i < k; ++i) {
        ListNode* head = new ListNode(0);
        write = head;
        for (int j = 0; j < size + (i < rem ? 1 : 0); ++j) {
            if (cur == nullptr)
                break;
            write->next = new ListNode(cur->val);
            write = write->next;
            if (cur != nullptr) 
            { cur = cur->next; }
        }
        nodes[i] = head->next;
    }
    
    return nodes;
}

void InsertNode(ListNode*& head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}
vector<list<int>*> SplitList(list<int>& vals, int k) {
    // first push all into stack
    queue<list<int>*> qVal;
    vector<list<int>*> nodes;
    list<int>::iterator it;
    it = vals.begin();
    cout << endl;
    while (it != vals.end()) {
        cout << " " << *it;
    }

    return nodes;
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
