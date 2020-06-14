// RankOfNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int>& nums, int low, int high);
void qSort(vector<int>& nums, int low, int high);
int FindRank(vector<int> nums, int val);


typedef struct Node {
    int val;
    Node* left, * right;
    int leftSize;
    Node(int x) :val(x), left(nullptr), right(nullptr),leftSize(0) {}
}Node;

void Insert(Node*& root, int x);
Node* Alloc(int x);
void InOrder(Node* root);
int RankofBST(Node* root, int key, int& count,int& recur);
int RankofNode(Node* root, int key);



int main()
{
    vector<int> nums = { 2,9,20,13,4,11,4,19,21,7,4,9,7 };
    //
    Node* root = nullptr;
    cout << endl << "Rank with sorting is " <<  FindRank(nums, 9);
    // Alternative methods Use a BST.
    int rank = 0;
    for (int i : nums) {
        Insert(root, i);
        rank++;
    }
    cout << endl;
    // InOrder(root);
    int count = 0;
    int recur = 0;

    // cout << endl << "BST Rank " << RankofBST(root, 9, count, recur) <<  endl;
    // cout << " Full search Recurrence is " << recur << endl;
    recur = 0;
    cout << endl << "BST Node Rank is " << RankofNode(root, 9) << endl;
    // cout << " Efficient search Reccurrence is " << recur << endl;
}

int RankofNode(Node* root, int key) {
    // Base case
    if (root == nullptr)
        return -1;
    // Found the key return size of left subtree
    if (root->val == key)
        return root->leftSize;

    if (key < root->val) {
        return RankofNode(root->left, key);
    }
    else {
        int rightSize = RankofNode(root->right, key);
        return root->leftSize + 1 + rightSize;
    }
   
}

int RankofBST(Node* root, int key, int& count,int& recur) {
    // Base
    recur++;

    if (root == nullptr)
        return count - 1;

    // found the key return size of left subtree
    if (root->val <= key)
        count++;
    // Search tree
 
    RankofBST(root->left, key, count,recur);
    RankofBST(root->right, key, count,recur);
  
    return count - 1;
}

// Print in order rank into the nodes
void InOrder(Node* root) {
    if (root == nullptr)
        return;
    InOrder(root->left);
    cout << root->val << " " << endl;
    InOrder(root->right);
}

Node* Alloc(int x) {
    Node* temp = new Node(x);
    return temp;
}

void Insert(Node*& root, int x) {
    if (root == nullptr) {
        root = Alloc(x);
        return;
    }
    // Insert left or right
    if (x <= root->val) {
        Insert(root->left, x);
        root->leftSize++;     // Increment if inserting into left
    }
    else {
        Insert(root->right, x);
    }
}

int FindRank(vector<int> nums, int val) {
    // sort and return rank
    qSort(nums, 0, nums.size() - 1);

    int i = 0;
    while (nums[i] <= val) {
        i++;
    }
    return i-1;
}

void qSort(vector<int>& nums,int low, int high)
{
    // Find Pivot and then 
    if (low >= high)
        return;

    // Partition
    int index = partition(nums, low, high);

    // qsort left
    qSort(nums, low, index - 1);
    // qsort right
    qSort(nums, index, high);
}
int partition(vector<int>& nums, int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = nums[mid];
    // create low and high indexes
    while (low <= high) {

        while (nums[low] < pivot)
            low++;
        while (nums[high] > pivot)
            high--;

        // swap element
        if (low <= high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }

    return low;
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
