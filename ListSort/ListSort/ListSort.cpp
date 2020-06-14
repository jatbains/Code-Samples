// ListSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;

}ListNode;

int main()
{
    std::cout << "Hello World!\n";
}

ListNode* vectorSort(ListNode* head) {
    vector<int> nums;
    ListNode* temp = head;
    while (temp != NULL) {
        nums.push_back(temp->val);
        temp = temp->next;
    }
    // Sort the vector
    sort(nums.begin(), nums.end());

    temp = head;
    // Copy sorted elements into list
    for (int i = 0; i < nums.size(); i++) {
        temp->val = nums[i];
        temp = temp->next;
    }
    return head;
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
