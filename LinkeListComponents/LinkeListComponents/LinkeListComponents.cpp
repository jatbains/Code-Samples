// LinkeListComponents.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
}ListNode;

int main()
{
    std::cout << "Hello World!\n";
}

int numComponents(ListNode* head, vector<int>& G) {
    // Sort the vector
    set<int> Gset;
    set<int>::iterator it1,it2;
    for (int i : G)
        Gset.insert(i);

    ListNode* cur = head;

    int num = 0;
    
    while (cur != NULL) {
        it1 = Gset.find(cur->val);
        if (cur->next != nullptr)
            it2 = Gset.find(cur->next->val);
        if (it1 != Gset.end() && ((cur->next == NULL) || !(it2 != Gset.end())))
            num++;
        cur = cur->next;
    }
    return num;
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
