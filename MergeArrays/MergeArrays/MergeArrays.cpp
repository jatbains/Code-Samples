// MergeArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main()
{
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2,5,6 };

    merge(nums1, 3, nums2, 3);

    cout << endl;
    for (int i : nums1)
    {
        cout << i << " ";
    }
    cout << endl;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    // vector<int> merged = new vector<int>;
    int* merged = new int[m + n]();
    int j = 0, k = 0;
    int i = 0;
    
    while (j < m && k < n)
    {
        if (nums1[j] < nums2[k])
        {
            merged[i] = nums1[j];
            j++;
        }
        else
        {
            merged[i] = nums2[k];
            k++;
        }
        // Check for remaining in either array
        i++;
    }
    
    while (j < m)
    {
        merged[i] = nums1[j];
        i++;
        j++;
    }
    while (k < n)
    {
        merged[i] = nums2[k];
        k++;
        i++;
    }
    // Copy everything back into nums1
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = merged[i];
    }
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
